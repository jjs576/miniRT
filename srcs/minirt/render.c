/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:43:36 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/11 14:34:10 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		color_to_int(t_color color)
{
	return ((int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}

void			put_pixel(t_info *info, int x, int y, t_color color)
{
	char	*dst;

	dst = info->mlx.addr + (y * info->mlx.size_line + x * (info->mlx.bpp / 8));
	*(unsigned int*)dst = color_to_int(color);
}

static t_color	get_pixel(t_vec2i pixel, t_info *info)
{
	t_ray		ray;
	t_camera	*camera;
	double		fov_factor;

	camera = info->cur_cam;
	fov_factor = tan(camera->fov / 2 * (PI / 180));
	ray.origin.x = (2 * ((pixel.x + 0.5) / info->window.x) - 1) * fov_factor;
	ray.origin.y = (1 - (2 * ((pixel.y + 0.5) / info->window.y))) * fov_factor;
	ray.origin.z = -1;
	ray.origin = look_at(camera, ray.origin);
	if (info->window.x > info->window.y)
		ray.origin.x *= info->window.x / (double)info->window.y;
	else
		ray.origin.y *= info->window.y / (double)info->window.x;
	ray.direction = vec_norm(ray.origin);
	ray.origin = info->cur_cam->pos;
	return (ray_casting(ray, info));
}

static void		*render_thread(void *p)
{
	t_thread_info	*tinfo;
	int				i;

	tinfo = p;
	i = tinfo->start;
	while (i < (tinfo->info->window.x * tinfo->info->window.y))
	{
		tinfo->color[i] = get_pixel((t_vec2i){i / tinfo->info->window.y,
		i % tinfo->info->window.y}, tinfo->info);
		i += MAX_PTHREAD;
	}
	free(p);
	pthread_exit(NULL);
}

t_color			*render(t_info *info)
{
	t_color			*color;
	pthread_t		threads[MAX_PTHREAD];
	int				i;
	t_thread_info	*thread_info[MAX_PTHREAD];

	color = ft_calloc(info->window.x * info->window.y, sizeof(t_color));
	i = 0;
	while (i < MAX_PTHREAD)
	{
		thread_info[i] = thread_new(info, color, i);
		if (pthread_create(&threads[i], NULL, render_thread, thread_info[i]))
			print_error(E_THREAD);
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (pthread_join(threads[i], NULL))
			print_error(E_THREAD);
		i--;
	}
	return (color);
}
