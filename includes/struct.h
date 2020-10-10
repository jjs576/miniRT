/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:05:36 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/10 18:08:44 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_list
{
	int		type;
	void	*data;
	void	*prev;
	void	*next;
}				t_list;

typedef struct	s_file
{
	char	*name;
	char	*data;
	int		fd;
	int		size;
}				t_file;

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

typedef struct	s_scene
{
	t_resolution	res;
	t_ambient		ambient;
	t_list			*camera;
	t_list			*light;
	t_list			*object;
}				t_scene;

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
}				t_mlx;

#endif
