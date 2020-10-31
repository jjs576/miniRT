/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:16:07 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 19:33:30 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "scene.h"

typedef struct	s_file
{
	int		fd;
	char	*line;
	int		index;
	int		error;
}				t_file;


typedef struct	s_my_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	t_scene	*scene;
	t_file	*file;
}				t_my_mlx;

void			init_mlx(t_my_mlx *mlx);
void			create_image(t_my_mlx *mlx);
void			start_mlx(t_my_mlx *mlx);
void			export_bmp(t_my_mlx *mlx);

t_file			*make_file(int fd);
int				open_file(char *path);
int				read_file(t_my_mlx *mlx);
#endif
