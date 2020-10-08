/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:36:05 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/08 16:29:58 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_sphere(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_sphere	sphere;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, sphere.center);
	count += parse_space(s + count);
	count += parse_double(s + count, &sphere.diameter);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, sphere.color);
	push_back(&scene->object, T_SPHERE, &sphere);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_plane(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_plane		plane;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, plane.point);
	count += parse_space(s + count);
	count += parse_multi_double(s + count, plane.axis);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, plane.color);
	push_back(&scene->object, T_PLANE, &plane);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_square(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_square	square;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, square.center);
	count += parse_space(s + count);
	count += parse_multi_double(s + count, square.axis);
	count += parse_space(s + count);
	count += parse_double(s + count, &square.size);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, square.color);
	push_back(&scene->object, T_SQUARE, &square);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_cylinder(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_cylinder	cylinder;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, cylinder.point);
	count += parse_space(s + count);
	count += parse_multi_double(s + count, cylinder.axis);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, cylinder.color);
	count += parse_space(s + count);
	count += parse_double(s + count, &cylinder.diameter);
	count += parse_space(s + count);
	count += parse_double(s + count, &cylinder.height);
	push_back(&scene->object, T_CYLINDER, &cylinder);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}

int		parse_triangle(char *str, t_scene *scene)
{
	char		*s;
	int			count;
	t_triangle	triangle;

	count = 1;
	s = str + count;
	count += parse_space(s + count);
	count += parse_multi_double(s + count, triangle.point[0]);
	count += parse_space(s + count);
	count += parse_multi_double(s + count, triangle.point[1]);
	count += parse_space(s + count);
	count += parse_multi_double(s + count, triangle.point[2]);
	count += parse_space(s + count);
	count += parse_multi_int(s + count, triangle.color);
	push_back(&scene->object, T_TRIANGLE, &triangle);
	if (*(s + count) == '\n')
		return (count);
	else
		return (-1);
}
