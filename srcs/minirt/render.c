/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:42 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/04 20:08:46 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void		render_pixel(t_thread_info *data, int y, int color)
{

}

static void	get_draw_point(int *x, int *y, t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->q_size)
	{
		if (scene->queue[i] == 0)
		{
			*x = i % scene->width;
			*y = i / scene->width;
			scene->queue[i] = 1;
			return ;
		}
	}
	*x = -1;
}

void		*run_thread(void *arg)
{
	t_thread_info	*info;
	int				x;
	int				y;
	int				i;
	t_vec			*color;

	info = (t_thread_info*)arg;
	while (TRUE)
	{
		pthread_mutex_lock(info->mutex);
		get_draw_point(&x, &y, info->scene);
		pthread_mutex_unlock(info->mutex);
		if (x == -1)
			break ;
		color = make_vector_zero();
		// 연산
		i = -1;
		while (++i < MAX_CALC)
			;
	}
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
