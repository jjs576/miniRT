/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:54:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 17:00:30 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		hook_key(int keycode, t_info *info)
{
	const	t_key	keys[] = {
		{KEY_ESC, &exit_mlx},
		{KEY_Q, &exit_mlx},
		{KEY_P, &switch_cam_next},
		{KEY_O, &switch_cam_prev},
		{KEY_W, &cam_move},
		{KEY_A, &cam_move},
		{KEY_S, &cam_move},
		{KEY_D, &cam_move},
		{KEY_LSHIFT, &cam_move},
		{KEY_SPACE, &cam_move},
		{KEY_LEFT, &cam_rotate_lr},
		{KEY_RIGHT, &cam_rotate_lr},
		{KEY_UP, &cam_rotate_ud},
		{KEY_DOWN, &cam_rotate_ud},
		{0, NULL}
	};
	int				i;

	i = -1;
	while (keys[++i].func)
		if (keys[i].key == keycode)
		{
			keys[i].func(keycode, info);
			break ;
		}
	return (0);
}
