/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:19:50 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/02 15:27:34 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

#include "minirt.h"
#include "scene.h"
#include "my_mlx.h"

typedef struct s_thread_data
{
	char			*data;
	t_scene			*scene;
	int				x;
	int				bpp;
	int				size_line;
	pthread_mutex_t	*mutex;
}				t_thread_data;

t_thread_data	*create_data(t_my_mlx *mlx, int i, pthread_mutex_t *mutex);
void			*run_thread(void *arguments);

#endif
