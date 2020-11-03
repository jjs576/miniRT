/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:40:00 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/03 10:11:28 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread.h"

t_thread_info	*create_info(int num, t_object *camera,
	t_scene *scene, pthread_mutex_t *mutex)
{
	t_thread_info	*info;
	info = (t_thread_info*)ft_calloc(1, sizeof(t_thread_info));
	info->num = num;
	info->camera = camera;
	info->scene = scene;
	info->mutex = mutex;
	return (info);
}

