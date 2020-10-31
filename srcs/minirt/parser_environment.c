/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:09:02 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 17:07:35 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	parse_resolution(t_my_mlx *mlx)
{
	mlx->file->index = 1;
	parse_space(mlx);
	mlx->scene->width = parse_int(mlx);
	parse_space(mlx);
	mlx->scene->height = parse_int(mlx);
	parse_space(mlx);
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_ambient(t_my_mlx *mlx)
{
	t_object	*light;

	mlx->file->index = 1;
	light = make_object(T_AMBIENT | T_LIGHT);
	parse_space(mlx);
	light->intensity = parse_float(mlx);
	parse_space(mlx);
	light->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	mlx->scene->total_intensity += light->intensity;
	mlx->scene->lights[mlx->scene->num_light++] = *light;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_camera(t_my_mlx *mlx)
{
	t_object	*camera;

	mlx->file->index = 1;
	camera = make_object(T_CAMERA);
	parse_space(mlx);
	camera->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	camera->axis = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	camera->fov = parse_int(mlx);
	parse_space(mlx);
	mlx->scene->cameras[mlx->scene->num_camera++] = *camera;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_light(t_my_mlx *mlx)
{
	t_object	*light;


	mlx->file->index = 1;
	light = make_object(T_LIGHT);
	parse_space(mlx);
	light->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	light->intensity = parse_float(mlx);
	parse_space(mlx);
	light->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	mlx->scene->total_intensity += light->intensity;
	mlx->scene->lights[mlx->scene->num_light++] = *light;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}
