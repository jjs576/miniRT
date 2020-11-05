/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:04:26 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 19:43:52 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d	vec_new(double x, double y, double z)
{
	t_vec3d	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_vec3d	vec_norm(t_vec3d vec)
{
	double	len;

	len = vec_len(vec);
	return (vec_new(vec.x / len, vec.y / len, vec.z / len));
}

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
