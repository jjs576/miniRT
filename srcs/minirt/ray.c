/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:24:56 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 20:57:01 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static BOOL		ray_blocked(
	t_object *object, t_light *light, t_ray ray, t_info *info)
{
	t_list		*objects;
	t_result	ret;
	double		dist;

	objects = info->objects;
	dist = vec_dist(ray.origin, light->pos);
	while (objects)
	{
		if (objects->content != object)
		{
			ret = object_distance((t_object*)objects->content, ray, info);
			if (ret.distance < dist)
				return (TRUE);
		}
		objects = objects->next;
	}
	return (FALSE);
}

static t_color	cast_light(
	t_result result, t_ray ray, t_light *light, t_info *info)
{
	t_vec3d	norm;
	t_vec3d	light_dir;
	double	factor;

	if (info->scene.ambient_ratio == 1)
		return (result.color);
	if (ray_blocked(result.object, light, (t_ray){result.pos,
		vec_norm(vec_sub(light->pos, result.pos))}, info))
		return (color_new(0, 0, 0));
	light_dir = vec_norm(vec_sub(light->pos, result.pos));
	norm = normal(result, ray, info);
	factor = vec_dot_prod(light_dir, norm);
	if (factor < 0)
		return (color_new(0, 0, 0));
	factor *= light->ratio;
	factor /= 4 * PI * pow(vec_dist(light->pos, result.pos), 2);
	return (color_mul(color_mix_light(light->color, result.object->color),
		fmin(factor, 1)));
}

static t_color	ray_casting_light(t_result result, t_ray ray, t_info *info)
{
	t_color	ret;
	t_list	*lights;

	ret = color_mul(info->scene.ambient_color, info->scene.ambient_ratio);
	ret = color_mix_light(result.object->color, ret);
	lights = info->lights;
	while (lights)
	{
		ret = color_add(ret,
			cast_light(result, ray, (t_light*)lights->content, info));
		lights = lights->next;
	}
	return (ret);
}

static t_result	ray_casting_object(t_ray ray, t_info *info)
{
	t_list		*cur_object;
	t_object	*closest_object;
	t_result	result;
	t_result	result_closest;
	double		min_distance;

	min_distance = INFINITY;
	closest_object = 0;
	cur_object = info->objects;
	while (cur_object)
	{
		result = object_distance((t_object*)cur_object->content, ray, info);
		if (result.distance < min_distance)
		{
			closest_object = (t_object*)cur_object->content;
			min_distance = result.distance;
			result_closest = result;
		}
		cur_object = cur_object->next;
	}
	if (!closest_object)
		return ((t_result){0, vec_new(0, 0, 0), color_new(0, 0, 0), INFINITY});
	return (result_closest);
}

t_color			ray_casting(t_ray ray, t_info *info)
{
	t_result	result;

	result = ray_casting_object(ray, info);
	if (result.distance == INFINITY)
		return (color_new(0, 0, 0));
	return (ray_casting_light(result, ray, info));
}
