/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:42:38 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/10 17:50:44 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_resolution(char *str, t_scene *scene)
{
	char			*s;
	int				count;
	t_resolution	res;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_int(s + count, &res.x, FALSE);
	count += parse_space(s + count);
	count += parse_int(s + count, &res.y, FALSE);
	scene->res = res;
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_ambient(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_ambient	ambient;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_double(s + count, &ambient.ratio);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, ambient.color);
	scene->ambient = ambient;
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_camera(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_camera	camera;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, camera.point);
	count += parse_space(s + count);
	count += parse_multi_double(s + count, camera.axis);
	count += parse_space(s + count);
	count += parse_int(s + count, &camera.fov, FALSE);
	push_back(&scene->camera, T_CAMERA, &camera);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_light(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_light		light;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, light.point);
	count += parse_space(s + count);
	count += parse_double(s + count, &light.ratio);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, light.color);
	push_back(&scene->light, T_LIGHT, &light);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}
