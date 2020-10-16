/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:05:36 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/16 15:23:14 by jjoo             ###   ########.fr       */
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
	t_ambient		ambient;
	t_list			*camera;
	t_list			*light;
	t_list			*object;
	int				width;
	int				height;
}				t_scene;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	t_scene	*scene;
}				t_mlx;

#endif
