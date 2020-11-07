/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:39:33 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 19:42:53 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_result	result_new(t_object *object, t_vec3d pos, t_color color)
{
	t_result	ret;

	ret.object = object;
	ret.pos = pos;
	ret.color = color;
	return (ret);
}

t_result	result_dist_new(t_object *object, t_vec3d pos, t_color color,
	double distance)
{
	t_result	ret;

	ret.object = object;
	ret.pos = pos;
	ret.color = color;
	ret.distance = distance;
	return (ret);
}

t_result	result_inf(void)
{
	return (result_dist_new(NULL, vec_new(0, 0, 0), color_new(0, 0, 0),
		INFINITY));
}
