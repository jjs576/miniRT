/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 13:02:26 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# include "libft.h"
# include "mlx.h"

# define BOOL				int

# define MAX_OBJECT			1024
# define MAX_PTHREAD		128
# define MAX_CALC			10

# define TRUE				1
# define FALSE				0

# define T_SPHERE			1 << 0
# define T_PLANE			1 << 1
# define T_SQUARE			1 << 2
# define T_CYLINDER			1 << 3
# define T_TRIANGLE			1 << 4

# define E_UNDEFINED		0
# define E_ARGUMENTS		1
# define E_OPEN				2
# define E_READ				3
# define E_PARSE			4
# define E_MALLOC			5
# define E_THREAD			6
# define E_MUTEX			7

# define E_MSG				"Error - "
# define E_UNDEFINED_MSG	"undefined\n"
# define E_ARGUMENTS_MSG	"arguments\n"
# define E_OPEN_MSG			"open file\n"
# define E_READ_MSG			"read file\n"
# define E_PARSE_MSG		"parser\n"
# define E_MALLOC_MSG		"malloc\n"
# define E_THREAD_MSG		"thread\n"
# define E_MUTEX_MSG		"mutex\n"

/*
**	basic struct
*/

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

typedef struct	s_vec3d
{
	double	x;
	double	y;
	double	z;
}				t_vec3d;

typedef struct	s_vec2i
{
	int		x;
	int		y;
}				t_vec2i;

typedef struct	s_ray
{
	t_vec3d	origin;
	t_vec3d	direction;
}				t_ray;

typedef struct	s_matrix
{
	t_vec3d	forward;
	t_vec3d	right;
	t_vec3d	up;
	t_vec3d	translation;
}				t_matrix;

typedef struct	s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}				t_quaternion;

/*
**	objects
*/

typedef struct	s_object
{
	int		type;
	t_vec3d	pos[3];
	t_vec3d	vector;
	t_color	color;
	double	size;
	double	height;
	double	distance;
}				t_object;

typedef struct	s_camera
{
	t_vec3d			pos;
	t_vec3d			vector;
	t_matrix		matrix;
	int				fov;
	double			distance;
	t_quaternion	quat;
}				t_camera;

typedef struct	s_light
{
	t_vec3d		pos;
	double		ratio;
	t_color		color;
}				t_light;

/*
**	general
*/

typedef struct	s_window
{
	int		x;
	int		y;
	BOOL	window_isvalid;
	BOOL	rendered;
}				t_window;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx;

typedef struct	s_scene
{
	BOOL	save;
	double	ambient_ratio;
	t_color	ambient_color;
	BOOL	ambient_isvalid;
}				t_scene;

typedef struct	s_info
{
	t_list		*objects;
	t_list		*cameras;
	t_camera	*cur_cam;
	t_list		*lights;
	t_window	window;
	t_scene		scene;
	t_mlx		mlx;
}				t_info;

/*
**	utils
*/

typedef struct	s_thread_info
{
	t_color	*color;
	t_info	*info;
	int		start;
}				t_thread_info;

typedef struct	s_parser
{
	char	*id;
	void	(*func)(char **, t_info *);
}				t_parser;

typedef struct	s_error
{
	int		id;
	char	*msg;
}				t_error;


/*
**	functions
*/

void			parse_file(char *file, t_info *info);
void			parse_resolution(char **buf, t_info *info);
void			parse_ambient(char **buf, t_info *info);
void			parse_camera(char **buf, t_info *info);
void			parse_light(char **buf, t_info *info);
void			parse_plane(char **buf, t_info *info);
void			parse_sphere(char **buf, t_info *info);
void			parse_sqaure(char **buf, t_info *info);
void			parse_cylinder(char **buf, t_info *info);
void			parse_triangle(char **buf, t_info *info);

double			parse_double(char *str);
t_vec3d			parse_vector(char *str);
t_color			parse_color(char *str);

void			print_error(int errno);

void			free_2d(char **array);
#endif
