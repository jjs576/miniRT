/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:26:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/12 15:58:47 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static BOOL	init_mlx_img(t_info *info)
{
	info->mlx.mlx_img = mlx_new_image(info->mlx.mlx_ptr,
		info->window.x, info->window.y);
	if (!info->mlx.mlx_img)
		return (FALSE);
	info->mlx.addr = mlx_get_data_addr(info->mlx.mlx_img, &info->mlx.bpp,
		&info->mlx.size_line, &info->mlx.endian);
	if (!info->mlx.addr)
		return (FALSE);
	return (TRUE);
}
static int	hook_image(t_info *info)
{
	t_color	*image;
	int		x;
	int		y;

	if (info->window.rendered)
		return (0);
	info->window.rendered = TRUE;
	image = render(info);
	x = 0;
	while (x < info->window.x)
	{
		y = 0;
		while (y < info->window.y)
		{
			put_pixel(info, x, y, image[x * info->window.y + y]);
			y++;
		}
		x++;
	}
	free(image);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.mlx_img, 0, 0);
	return (0);
}

static int	hook_exit(t_info *info)
{
	free_info(info);
	exit(1);
	return (1);
}

BOOL		init(t_info *info)
{
	if (!(info->mlx.mlx_ptr = mlx_init()))
		return (FALSE);
	info->mlx.win_ptr = mlx_new_window(info->mlx.mlx_ptr,
		info->window.x, info->window.y, "MiniRT");
	if (!info->mlx.win_ptr)
		return (FALSE);
	if (!init_mlx_img(info))
		return (FALSE);
	mlx_hook(info->mlx.win_ptr, 17, 0L, &hook_exit, info);
	mlx_key_hook(info->mlx.win_ptr, &hook_key, info);
	mlx_loop_hook(info->mlx.mlx_ptr, &hook_image, info);
	return (TRUE);
}
