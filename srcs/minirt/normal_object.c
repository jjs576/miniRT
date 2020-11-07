/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:35:43 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 19:58:01 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec3d	adjust_normal(t_vec3d ray_dir, t_vec3d norm)
{
	double	angle;

	angle = vec_dot_prod(norm, ray_dir);
	angle /= vec_len(norm) * vec_len(ray_dir);
	if (acos(angle) < (M_PI_2))
		return (vec_mul(norm, -1));
	return (norm);
}

t_vec3d	norm_tr(t_result result, t_ray ray, t_info *info)
{
	t_vec3d	v[3];

	(void)info;
	v[0] = vec_sub(result.object->pos[1], result.object->pos[0]);
	v[1] = vec_sub(result.object->pos[2], result.object->pos[0]);
	v[2] = vec_cross_prod(v[0], v[1]);
	return (adjust_normal(ray.direction, vec_norm(v[2])));
}

t_vec3d	norm_cy(t_result result, t_ray ray, t_info *info)
{
	(void)ray;
	(void)info;
	return (result.object->vector);
}

t_vec3d	norm_pl(t_result result, t_ray ray, t_info *info)
{
	(void)info;
	return (adjust_normal(ray.direction, result.object->vector));
}

t_vec3d	norm_sp(t_result result, t_ray ray, t_info *info)
{
	(void)info;
	return (adjust_normal(ray.direction,
		vec_atob(result.object->pos[0], result.pos)));
}

