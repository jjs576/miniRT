/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:27:41 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 19:49:36 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_result	object_distance(t_object *object, t_ray ray, t_info *info)
{
	t_result	(*dist_func)(t_object *, t_ray, t_info*);
	const void	*object_type[] = {
		&distance_sphere,
		&distance_plane,
		0,
		&distance_cylinder,
		&distance_triangle
	};
	dist_func = object_type[object->type];
	return ((*dist_func)(object, ray, info));
}
