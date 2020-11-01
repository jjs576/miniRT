/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:26:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/01 19:31:13 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include "minirt.h"

void	init_mlx(t_my_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr,
		mlx->scene->width, mlx->scene->height);
	mlx->data = mlx_get_data_addr(mlx->mlx_img,
		&mlx->bpp, &mlx->size_line, &mlx->endian);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		mlx->scene->width, mlx->scene->height, "miniRT");
}

void	start_mlx(t_my_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->mlx_img, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, handle_mlx, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_mlx, 0);
}

int		handle_mlx(int k, t_my_mlx *mlx)
{
	k;
	mlx;
	return (0);
}

int		exit_mlx(void)
{
	exit(0);
	return (0);
}

void	create_image(t_my_mlx *mlx)
{
	mlx;
}

