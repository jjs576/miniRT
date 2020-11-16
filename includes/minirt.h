/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/16 14:45:22 by jjoo             ###   ########.fr       */
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

# define PI					M_PI
# define EPS				1e-6
# define MOVE_SPEED			1.0
# define MAX_PTHREAD		42

# define TRUE				1
# define FALSE				0

# define T_SPHERE			0
# define T_PLANE			1
# define T_SQUARE			2
# define T_CYLINDER			3
# define T_TRIANGLE			4

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

# define KEY_CMD			259
# define KEY_ESC			53
# define KEY_SPACE			49
# define KEY_LSHIFT			257
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_O				31
# define KEY_G				5
# define KEY_P				35
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_Q				12
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124

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
	uint16_t	x;
	uint16_t	y;
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

typedef struct	s_result
{
	t_object	*object;
	t_vec3d		pos;
	t_color		color;
	double		distance;
}				t_result;

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

typedef struct	s_key
{
	int		key;
	void	(*func)(int, t_info*);
}				t_key;

/*
**	thread functions
*/

t_thread_info	*thread_new(t_info *info, t_color *color, int start);

/*
**	camera functions
*/

void			cam_move(int keycode, t_info *data);
void			cam_rotate_lr(int keycode, t_info *data);
void			cam_rotate_ud(int keycode, t_info *data);
void			switch_cam_next(int keycode, t_info *data);
void			switch_cam_prev(int keycode, t_info *data);

/*
**	input functions
*/

int				hook_key(int keycode, t_info *info);

/*
**	rendering functions
*/

t_vec3d			look_at(t_camera *camera, t_vec3d ray);
void			put_pixel(t_info *info, int x, int y, t_color color);
t_color			*render(t_info *info);
void			export_bmp(t_info *info);

/*
**	normalize functions
*/

t_vec3d			normal(t_result result, t_ray ray, t_info *info);
t_vec3d			norm_sp(t_result result, t_ray ray, t_info *info);
t_vec3d			norm_pl(t_result result, t_ray ray, t_info *info);
t_vec3d			norm_cy(t_result result, t_ray ray, t_info *info);
t_vec3d			norm_tr(t_result result, t_ray ray, t_info *info);

/*
**	distance functions
*/

t_result		distance_triangle(t_object *triangle, t_ray ray, t_info *info);
t_result		distance_plane(t_object *plane, t_ray ray, t_info *info);
t_result		distance_sphere(t_object *sphere, t_ray ray, t_info *info);
t_result		distance_cylinder(t_object *cylinder, t_ray ray, t_info *info);
t_result		object_distance(t_object *object, t_ray ray, t_info *info);

/*
**	ray functions
*/

t_color			ray_casting(t_ray ray, t_info *info);

/*
**	mlx functions
*/

BOOL			init(t_info *info);

/*
**	parse functions
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

void			divide_square(t_object *sq, t_info *info);
double			parse_double(char *str);
t_vec3d			parse_vector(char *str);
t_color			parse_color(char *str);

/*
**	vector functions
*/

t_vec3d			vec_new(double x, double y, double z);
t_vec3d			vec_norm(t_vec3d vec);
double			vec_len(t_vec3d v);
t_vec3d			mul_vec_matrix(t_vec3d v, t_matrix m);

t_vec3d			vec_add(t_vec3d v1, t_vec3d v2);
t_vec3d			vec_sub(t_vec3d v1, t_vec3d v2);
t_vec3d			vec_mul(t_vec3d v, double factor);
double			vec_sqr(t_vec3d v);
double			vec_dist(t_vec3d v1, t_vec3d v2);

t_vec3d			vec_prod(t_vec3d v1, t_vec3d v2);
t_vec3d			vec_cross_prod(t_vec3d v1, t_vec3d v2);
double			vec_dot_prod(t_vec3d v1, t_vec3d v2);
t_vec3d			vec_atob(t_vec3d a, t_vec3d b);

/*
**	quaternion functions
*/

t_quaternion	quat_new(double w, double x, double y, double z);
t_quaternion	quat_mul(t_quaternion q1, t_quaternion q2);
t_quaternion	quat_conj(t_quaternion q);
t_quaternion	quat_norm(t_quaternion q);
t_quaternion	quat_local_rotate(t_vec3d axis, double angle);
t_quaternion	rotate_cam(t_vec3d vector, t_vec3d axis, double angle);

/*
**	matrix functions
*/

t_matrix		matrix_new(t_vec3d vec);
t_matrix		matrix_mul(t_matrix m, double factor);
t_matrix		matrix_prod(t_matrix a, t_matrix b);
t_matrix		matrix_norm(t_matrix m);
t_matrix		quat_to_matrix(t_quaternion q);

/*
**	color functions
*/

t_color			color_new(int r, int g, int b);
t_color			color_mix(t_color c1, t_color c2);
t_color			color_mul(t_color c, double fact);
t_color			color_add(t_color c1, t_color c2);
t_color			color_mix_light(t_color c, t_color l);

/*
**	util functions
*/

void			print_error(int errno);
void			free_list(t_list *list, void (*func)(void *));
void			free_info(t_info *info);
void			exit_free(t_info *info);
void			free_2d(char **array);
void			exit_mlx(int keycode, t_info *info);
t_result		result_new(t_object *object, t_vec3d pos, t_color color);
t_result		result_dist_new(t_object *object, t_vec3d pos, t_color color,
	double distance);
t_result		result_inf(void);
void			swap_double(double *d1, double *d2);
size_t			char_arrlen(char **array);

#endif
