/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:19:50 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/04 20:08:38 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

#include "my_mlx.h"
#include "minirt.h"

typedef struct s_thread_info
{
	int				num;
	t_object		*camera;
	t_scene			*scene;
	pthread_mutex_t	*mutex;
}				t_thread_info;

t_thread_info	*create_info(int num, t_object *camera,
	t_scene *scene, pthread_mutex_t *mutex);
void			*run_thread(void *arguments);

#endif
