/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:05:36 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/07 21:49:19 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_file
{
	char	*name;
	char	*data;
	int		fd;
	int		length;
}				t_file;

typedef struct	s_scene
{
	t_resolution	res;
	t_ambient		ambient;
	t_list			*camera;
	t_list			*light;
	t_list			*object;
	
}				t_scene;

typedef struct	s_resolution
{
	int	x;
	int	y;
}				t_resolution;

typedef struct	s_ambient
{
	double	ratio;
	int		color[3];
}				t_ambient;

typedef struct	s_camera
{
	double	point[3];
	double	axis[3];
	int		fov;
}				t_camera;

typedef struct	s_light
{
	double	point[3];
	double	ratio;
	int		color[3];
}				t_light;

typedef struct	s_sphere
{
	double	point[3];
	double	diameter;
	int		color[3];
}				t_sphere;

typedef struct	s_plane
{
	double	point[3];
	double	axis[3];
	int		color[3];
}				t_plane;

typedef struct	s_square
{
	double	center[3];
	double	axix[3];
	double	size;
	int		color[3];
}				t_square;

typedef struct	s_cylinder
{
	double	point[3];
	double	axis[3];
	double	diameter;
	double	height;
	int		color[3];
}				t_cylinder;

typedef struct	s_triangle
{
	double	point[3][3];
	int		color[3];
}				t_triangle;

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
}				t_mlx;

#endif
