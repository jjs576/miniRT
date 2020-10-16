/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 15:12:18 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/16 15:25:19 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_mlx *init_mlx(t_scene *scene)
{
	t_mlx	*mlx;
	if (!(mlx = malloc(sizeof(t_mlx))))
		check_error(E_MALLOC_FAIL);
	mlx->mlx_ptr = mlx_init();
	mlx->scene = scene;
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr,
	mlx->scene->width, mlx->scene->height);
	mlx->data = mlx_get_data_addr(mlx->mlx_img,
	&mlx->bpp, &mlx->size_line, &mlx->endian);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
	mlx->scene->width, mlx->scene->height, "miniRT");
	return (mlx);
}
