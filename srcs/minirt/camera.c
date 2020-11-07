/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:50:50 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 17:08:49 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			cam_move(int keycode, t_info *info)
{
	info->window.rendered = FALSE;
	if (keycode == KEY_A)
		info->cur_cam->pos = vec_sub(info->cur_cam->pos,
		vec_mul(info->cur_cam->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_D)
		info->cur_cam->pos = vec_add(info->cur_cam->pos,
		vec_mul(info->cur_cam->matrix.right, MOVE_SPEED));
	else if (keycode == KEY_W)
		info->cur_cam->pos = vec_sub(info->cur_cam->pos,
		vec_mul(info->cur_cam->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_S)
		info->cur_cam->pos = vec_add(info->cur_cam->pos,
		vec_mul(info->cur_cam->matrix.forward, MOVE_SPEED));
	else if (keycode == KEY_LSHIFT)
		info->cur_cam->pos = vec_sub(info->cur_cam->pos,
		vec_mul(info->cur_cam->matrix.up, MOVE_SPEED));
	else if (keycode == KEY_SPACE)
		info->cur_cam->pos = vec_add(info->cur_cam->pos,
		vec_mul(info->cur_cam->matrix.up, MOVE_SPEED));
	else
		info->window.rendered = TRUE;
}

void			cam_rotate_lr(int keycode, t_info *info)
{
	int	ratio;

	ratio = 0;
	info->window.rendered = FALSE;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		ratio = keycode == KEY_LEFT ? 5 : -5;
		info->cur_cam->quat = rotate_cam(info->cur_cam->matrix.forward,
			info->cur_cam->matrix.up, ratio * PI / 180);
		info->cur_cam->vector = vec_new(info->cur_cam->quat.x,
			info->cur_cam->quat.y, info->cur_cam->quat.z);
		info->cur_cam->vector = vec_mul(info->cur_cam->vector, -1);
		info->cur_cam->matrix = matrix_new(info->cur_cam->vector);
		info->cur_cam->matrix = matrix_norm(info->cur_cam->matrix);
	}
	else
		info->window.rendered = TRUE;
}

void			cam_rotate_ud(int keycode, t_info *info)
{
int ratio;

	ratio = 0;
	info->window.rendered = FALSE;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		ratio = keycode == KEY_UP ? 5 : -5;
		info->cur_cam->quat = rotate_cam(info->cur_cam->matrix.forward,
			info->cur_cam->matrix.right, ratio * PI / 180);
		info->cur_cam->quat = quat_norm(info->cur_cam->quat);
		info->cur_cam->vector = vec_new(info->cur_cam->quat.x,
			info->cur_cam->quat.y, info->cur_cam->quat.z);
		info->cur_cam->vector = vec_mul(info->cur_cam->vector, -1);
		info->cur_cam->matrix = matrix_new(info->cur_cam->vector);
		info->cur_cam->matrix = matrix_norm(info->cur_cam->matrix);
	}
	else
		info->window.rendered = TRUE;
}

void			switch_cam_next(int keycode, t_info *info)
{
	t_list		*cameras;

	(void)keycode;
	info->window.rendered = FALSE;
	cameras = info->cameras;
	while (cameras->next)
	{
		if (cameras->content == info->cur_cam)
			break ;
		cameras = cameras->next;
	}
	if (cameras->next)
		info->cur_cam = cameras->next->content;
	else if (!cameras->next)
	{
		while (cameras->prev)
			cameras = cameras->prev;
		info->cur_cam = cameras->content;
	}
}

void			switch_cam_prev(int keycode, t_info *info)
{
	t_list		*cameras;

	(void)keycode;
	info->window.rendered = FALSE;
	cameras = info->cameras;
	while (cameras->next)
	{
		if (cameras->content == info->cur_cam)
			break ;
		cameras = cameras->next;
	}
	if (cameras->prev)
		info->cur_cam = cameras->prev->content;
	else if (!cameras->prev)
	{
		while (cameras->next)
			cameras = cameras->next;
		info->cur_cam = cameras->content;
	}
}
