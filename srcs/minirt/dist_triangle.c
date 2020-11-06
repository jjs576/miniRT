/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:53:05 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 20:59:31 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	check_tri_edge(t_object *triangle, t_vec3d norm, t_vec3d p)
{
	t_vec3d	edge[3];
	t_vec3d	c[3];

	edge[0] = vec_sub(triangle->pos[1], triangle->pos[0]);
	edge[1] = vec_sub(triangle->pos[2], triangle->pos[1]);
	edge[2] = vec_sub(triangle->pos[0], triangle->pos[2]);
	c[0] = vec_sub(p, triangle->pos[0]);
	c[1] = vec_sub(p, triangle->pos[1]);
	c[2] = vec_sub(p, triangle->pos[2]);
	return (vec_dot_prod(norm, vec_cross_prod(edge[0], c[0])) >= 0 &&
			vec_dot_prod(norm, vec_cross_prod(edge[1], c[1])) >= 0 &&
			vec_dot_prod(norm, vec_cross_prod(edge[2], c[2])) >= 0);
}

t_result		distance_triangle(t_object *triangle, t_ray ray, t_info *info)
{
	t_result	tr_plane;
	t_object	plane;

	plane.type = T_PLANE;
	plane.pos[0] = triangle->pos[0];
	plane.vector = normal((t_result){triangle, vec_new(0, 0, 0),
		color_new(0, 0, 0), 0}, ray, info);
	if (vec_dot_prod(plane.vector, ray.direction) == 0)
		return ((t_result){0, vec_new(0, 0, 0), color_new(0, 0, 0), INFINITY});
	tr_plane = object_distance(&plane, ray, info);
	if (tr_plane.distance == INFINITY)
		return ((t_result){0, vec_new(0, 0, 0), color_new(0, 0, 0), INFINITY});
	if (!check_tri_edge(triangle, plane.vector, tr_plane.pos) &&
		!check_tri_edge(triangle, vec_mul(plane.vector, -1),
		tr_plane.pos))
		return ((t_result){0, vec_new(0, 0, 0), color_new(0, 0, 0), INFINITY});
	return ((t_result){triangle, tr_plane.pos, triangle->color,
			vec_dist(ray.origin, tr_plane.pos)});
}
