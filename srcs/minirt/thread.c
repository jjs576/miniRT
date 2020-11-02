/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:40:00 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/02 19:30:25 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

t_thread_data	*create_data(t_my_mlx *mlx, int i, pthread_mutex_t *mutex)
{
	t_thread_data	*data;
	data = (t_thread_data*)ft_calloc(1, sizeof(t_thread_data));
	data->data = mlx->data;
	data->x = -(mlx->scene->width / 2) + i;
	data->bpp = mlx->bpp;
	data->size_line = mlx->size_line;
	data->mutex = mutex;
	return (data);
}

void			*run_thread(void *arg)
{

}
