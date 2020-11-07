/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:29:50 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 19:49:38 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d			normal(t_result result, t_ray ray, t_info *info)
{
	t_vec3d		(*norm_func)(t_result, t_ray, t_info*);
	const void	*object_type[] = {
		&norm_sp,
		&norm_pl,
		0,
		&norm_cy,
		&norm_tr
	};
	norm_func = object_type[result.object->type];
	return ((*norm_func)(result, ray,info));
}
