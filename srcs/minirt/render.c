/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:42 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/03 10:12:40 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_pixel(t_thread_info *data, int y, int color)
{

}

void	*run_thread(void *arg)
{
	//할일 : 대기열 구현, 연산과정 따라치기
}

void	render(t_object *cam, t_my_mlx *mlx)
{
	pthread_t		*threads;
	int				num_thread;
	t_thread_info	*info;
	pthread_mutex_t	*mutex;

	pthread_mutex_init(&mutex, NULL);
	threads = (pthread_t)ft_calloc(MAX_PTHREAD, sizeof(pthread_t));
	num_thread = -1;
	while (++num_thread < MAX_PTHREAD)
	{
		info = create_info(num_thread + 1, cam, mlx->scene, &mutex);
		pthread_create(&threads[num_thread], NULL, run_thread, (void*)info);
	}
	num_thread = -1;
	while (++num_thread < MAX_PTHREAD)
		pthread_join(threads[num_thread], NULL);
	free(threads);
}
