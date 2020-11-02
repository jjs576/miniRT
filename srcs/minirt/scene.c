/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:25:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/02 16:19:33 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minirt.h"

t_scene	*make_scene()
{
	t_scene	*s;

	s = (t_scene*)ft_calloc(1, sizeof(t_scene));
	s->lights = (t_object*)ft_calloc(MAX_OBJECT, sizeof(t_object));
	s->objects = (t_object*)ft_calloc(MAX_OBJECT, sizeof(t_object));
	s->cameras = (t_object*)ft_calloc(MAX_OBJECT, sizeof(t_object));
	return (s);
}

t_scene		*copy_scene(t_scene *origin)
{
	t_scene *s;

	s = (t_scene*)ft_calloc(1, sizeof(t_scene));
	s->width = origin->width;
	s->height = origin->height;
	s->num_object = origin->num_object;
	s->num_light = origin->num_light;
	s->num_camera = origin->num_camera;
	s->total_intensity = origin->total_intensity;
	s->lights = origin->lights;
	s->objects = origin->objects;
	s->cameras = origin->cameras;
	return (s);
}
