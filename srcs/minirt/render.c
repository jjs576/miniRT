/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:42 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/02 16:24:08 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_pixel(t_thread_data *data, int y, int color)
{
	int	i;

	i = ((data->x) + (data->scene->width / 2)) *
		(data->bpp / 8) + (y * data->size_line);
	pthread_mutex_lock(data->mutex);
	data->data[i] = color;
	data->data[++i] = color >> 8;
	data->data[++i] = color >> 16;
	pthread_mutex_unlock(data->mutex);
}
