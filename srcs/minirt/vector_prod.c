/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_prod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:39:59 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 12:41:25 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d	vec_prod(t_vec3d v1, t_vec3d v2)
{
	return (vec_new(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_vec3d vec_cross_prod(t_vec3d v1, t_vec3d v2)
{
	return (vec_new((v1.y * v2.z) - (v1.z * v2.y),
					(v1.z * v2.x) - (v1.x * v2.z),
					(v1.x * v2.y) - (v1.y * v2.x)));
}

double	vec_dot_prod(t_vec3d v1, t_vec3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

