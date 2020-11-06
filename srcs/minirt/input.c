/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:54:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 21:10:45 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		hook_key(int keycode, t_info *info)
{
	char	*keystring;

	keystring = ft_itoa(keycode);
	mlx_string_put(info->mlx.mlx_ptr, info->mlx.win_ptr,
		(info->window.x / 2) - 10, 20, 0xFFFFFF, keystring);
	free(keystring);
	//key(keycode, info);
	return (0);
}

