/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:47 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 17:48:21 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	parse_sphere(t_my_mlx *mlx)
{
	t_object	*sphere;

	mlx->file->index = 2;
	sphere = make_object(T_SPHERE);
	parse_space(mlx);
	sphere->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	sphere->diameter = parse_float(mlx);
	parse_space(mlx);
	sphere->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	mlx->scene->objects[mlx->scene->num_object++] = *sphere;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_plane(t_my_mlx *mlx)
{
	t_object	*plane;

	mlx->file->index = 2;
	plane = make_object(T_PLANE);
	parse_space(mlx);
	plane->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	plane->axis = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	plane->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	mlx->scene->objects[mlx->scene->num_object++] = *plane;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_square(t_my_mlx *mlx)
{
	t_object	*square;

	mlx->file->index = 2;
	square = make_object(T_SQUARE);
	parse_space(mlx);
	square->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	square->axis = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	square->size = parse_float(mlx);
	parse_space(mlx);
	square->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	mlx->scene->objects[mlx->scene->num_object++] = *square;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_cylinder(t_my_mlx *mlx)
{
	t_object	*cylinder;

	mlx->file->index = 2;
	cylinder = make_object(T_CYLINDER);
	parse_space(mlx);
	cylinder->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	cylinder->axis = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	cylinder->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	cylinder->diameter = parse_float(mlx);
	parse_space(mlx);
	cylinder->height = parse_float(mlx);
	parse_space(mlx);
	mlx->scene->objects[mlx->scene->num_object++] = *cylinder;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}

void	parse_triangle(t_my_mlx *mlx)
{
	t_object	*triangle;

	mlx->file->index = 2;
	triangle = make_object(T_TRIANGLE);
	parse_space(mlx);
	triangle->point = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	triangle->point2 = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	triangle->point3 = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	triangle->color = make_vector(parse_multi_float(mlx));
	parse_space(mlx);
	mlx->scene->objects[mlx->scene->num_object++] = *triangle;
	if (*(mlx->file->line + mlx->file->index) != 0)
		mlx->file->error = TRUE;
}
