/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:18:32 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/13 16:37:07 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_result	distance_plane(t_object *plane, t_ray ray, t_info *info)
{
	double	distance;

	(void)info;
	distance = vec_dot_prod(vec_sub(plane->pos[0], ray.origin), plane->vector)
		/ vec_dot_prod(plane->vector, ray.direction);
	if (distance < 0)
		return (result_inf());
	return (result_dist_new(
			plane, vec_add(ray.origin, vec_mul(ray.direction, distance)),
			plane->color, distance));
}

t_result	distance_sphere(t_object *sphere, t_ray ray, t_info *info)
{
	double	distance[2];
	double	center;
	double	radius;
	double	d2;
	t_vec3d	p;

	(void)info;
	p = vec_sub(sphere->pos[0], ray.origin);
	center = vec_dot_prod(p, ray.direction);
	d2 = vec_dot_prod(p, p) - pow(center, 2);
	if (d2 > sphere->size / 2)
		return (result_inf());
	radius = sqrt(sphere->size / 2 - d2);
	distance[0] = center - radius;
	distance[1] = center + radius;
	if (distance[0] > distance[1])
		swap_double(&distance[0], &distance[1]);
	if (distance[0] < 0)
	{
		distance[0] = distance[1];
		if (distance[0] < 0)
			return (result_inf());
	}
	return (result_dist_new(sphere, vec_add(ray.origin,
		vec_mul(ray.direction, distance[0])), sphere->color, distance[0]));
}

static int	init_cylinder(t_object *cylinder, t_ray ray, double *distance)
{
	double	abc[2];
	double	discr;
	t_vec3d	c[2];

	c[0] = vec_sub(ray.direction, vec_mul(cylinder->vector,
		vec_dot_prod(ray.direction, cylinder->vector)));
	c[1] = vec_sub(vec_sub(ray.origin, cylinder->pos[0]),
		vec_mul(cylinder->vector, vec_dot_prod(vec_sub(ray.origin,
			cylinder->pos[0]), cylinder->vector)));
	abc[0] = 2.0 * vec_dot_prod(c[0], c[1]);
	abc[1] = vec_sqr(c[1]) - pow(cylinder->size / 2, 2);
	discr = pow(abc[0], 2) - 4.0 * vec_sqr(c[0]) * abc[1];
	if (discr < 0.0)
		return (FALSE);
	else if (discr < EPS)
	{
		distance[0] = -0.5 * abc[0] / vec_sqr(c[0]);
		distance[1] = distance[0];
	}
	else
	{
		distance[0] = (-abc[0] + sqrt(discr)) / (2.0 * vec_sqr(c[0]));
		distance[1] = (-abc[0] - sqrt(discr)) / (2.0 * vec_sqr(c[0]));
	}
	return (TRUE);
}

static void	init_cylinder_value(t_object *cylinder, t_vec3d *p)
{
	p[0] = vec_sub(cylinder->pos[0],
		vec_mul(cylinder->vector, cylinder->height / 2.0));
	p[1] = vec_add(cylinder->pos[0],
		vec_mul(cylinder->vector, cylinder->height / 2.0));
}

t_result	distance_cylinder(t_object *cylinder, t_ray ray, t_info *info)
{
	t_vec3d	p[2];
	t_vec3d	q;
	double	distance[2];
	double	ret;

	(void)info;
	init_cylinder_value(cylinder, p);
	ret = -1.0;
	if (init_cylinder(cylinder, ray, distance) == TRUE)
	{
		q = vec_add(ray.origin, vec_mul(ray.direction, distance[0]));
		if (distance[0] > EPS &&
		vec_dot_prod(cylinder->vector, vec_sub(q, p[0])) > 0.0 &&
		vec_dot_prod(cylinder->vector, vec_sub(q, p[1])) < 0.0)
			ret = distance[0];
		q = vec_add(ray.origin, vec_mul(ray.direction, distance[1]));
		if (distance[1] > EPS &&
		vec_dot_prod(cylinder->vector, vec_sub(q, p[0])) > 0.0 &&
		vec_dot_prod(cylinder->vector, vec_sub(q, p[1])) < 0.0)
			ret = (ret != -1.0) ? fmin(distance[0], distance[1]) : distance[1];
		if (ret > 0.0)
			return (result_dist_new(cylinder, vec_add(ray.origin,
				vec_mul(ray.direction, ret)), cylinder->color, ret));
	}
	return (result_inf());
}
