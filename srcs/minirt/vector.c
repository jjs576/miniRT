/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:04:26 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/10 17:24:00 by jjoo             ###   ########.fr       */
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

double	vec_len(t_vec3d v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vec3d	vec_norm(t_vec3d vec)
{
	double	len;

	len = vec_len(vec);
	return (vec_new(vec.x / len, vec.y / len, vec.z / len));
}

t_vec3d	mul_vec_matrix(t_vec3d v, t_matrix m)
{
	t_vec3d	ret;

	ret.x = v.x * m.right.x + v.y * m.up.x + v.z * m.forward.x;
	ret.y = v.x * m.right.y + v.y * m.up.y + v.z * m.forward.y;
	ret.z = v.x * m.right.z + v.y * m.up.z + v.z * m.forward.z;
	return (ret);
}
