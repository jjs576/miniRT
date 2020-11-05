/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:03:04 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 01:16:51 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_thread_info	*thread_new(t_info *info, t_color *color, int start)
{
	t_thread_info	*tinfo;

	tinfo = ft_calloc(1, sizeof(t_thread_info));
	tinfo->info = info;
	tinfo->color = color;
	tinfo->start = start;
	return (tinfo);
}
