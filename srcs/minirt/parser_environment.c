/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:09:02 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/16 12:47:31 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	parse_resolution(char **buf, t_info *info)
{
	const int	screen[2] = {1920, 1080};

	if (info->window.window_isvalid)
		print_error(E_PARSE);
	if (buf[1])
		info->window.x = ft_atoi(buf[1]);
	if (buf[2])
		info->window.y = ft_atoi(buf[2]);
	if (info->window.x <= 0 || info->window.y <= 0)
		print_error(E_PARSE);
	if (info->window.x > screen[0] && !info->scene.save)
		info->window.x = screen[0];
	if (info->window.y > screen[1] && !info->scene.save)
		info->window.y = screen[1];
	info->window.window_isvalid = TRUE;
}

void	parse_ambient(char **buf, t_info *info)
{
	if (info->scene.ambient_isvalid)
		print_error(E_PARSE);
	info->scene.ambient_ratio = parse_double(buf[1]);
	info->scene.ambient_color = parse_color(buf[2]);
	if (info->scene.ambient_ratio > 1 || info->scene.ambient_ratio < 0)
		print_error(E_PARSE);
	info->scene.ambient_isvalid = TRUE;
}

void	parse_camera(char **buf, t_info *info)
{
	t_camera	*camera;

	camera = (t_camera*)ft_calloc(1, sizeof(t_camera));
	camera->pos = parse_vector(buf[1]);
	camera->vector = parse_vector(buf[2]);
	if (camera->vector.x > 1 || camera->vector.x < -1 ||
		camera->vector.y > 1 || camera->vector.y < -1 ||
		camera->vector.z > 1 || camera->vector.z < -1)
		print_error(E_PARSE);
	camera->vector = vec_norm(camera->vector);
	camera->fov = ft_atoi(buf[3]);
	camera->quat = quat_new(1, 0, 0, 0);
	camera->matrix = matrix_new(camera->vector);
	if (camera->fov < 0 || camera->fov > 180)
		print_error(E_PARSE);
	if (!lst_new_back(&(info->cameras), camera))
		print_error(E_PARSE);
}

void	parse_light(char **buf, t_info *info)
{
	t_light	*light;

	light = (t_light*)ft_calloc(1, sizeof(t_light));
	light->pos = parse_vector(buf[1]);
	light->ratio = parse_double(buf[2]);
	light->color = parse_color(buf[3]);
	if (light->ratio > 1 || light->ratio < 0)
		print_error(E_PARSE);
	light->ratio *= 100;
	if (!lst_new_back(&(info->lights), light))
		print_error(E_PARSE);
}
