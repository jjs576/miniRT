/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:40:37 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 21:24:12 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d	vec_add(t_vec3d v1, t_vec3d v2)
{
	return (vec_new(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec3d	vec_sub(t_vec3d v1, t_vec3d v2)
{
	return (vec_new(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec3d	vec_mul(t_vec3d v, double factor)
{
	return (vec_new(v.x * factor, v.y * factor, v.z * factor));
}

double	vec_dist(t_vec3d v1, t_vec3d v2)
{
	return (sqrt(pow(v2.x - v1.x, 2) +
		pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2)));
}

double	vec_sqr(t_vec3d v)
{
	return (pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
}
