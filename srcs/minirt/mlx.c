/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:26:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 19:32:37 by jjoo             ###   ########.fr       */
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

void	create_image(t_my_mlx *mlx)
{
	
}
