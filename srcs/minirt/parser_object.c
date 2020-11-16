/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:47 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/16 14:48:44 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(char **buf, t_info *info)
{
	t_object	*obj;

	obj = (t_object*)ft_calloc(1, sizeof(t_object));
	if (char_arrlen(buf) != 4)
		print_error(E_PARSE);
	obj->type |= T_PLANE;
	obj->pos[0] = parse_vector(buf[1]);
	obj->vector = parse_vector(buf[2]);
	obj->color = parse_color(buf[3]);
	if (obj->vector.x > 1 || obj->vector.x < -1 ||
		obj->vector.y > 1 || obj->vector.y < -1 ||
		obj->vector.z > 1 || obj->vector.z < -1)
		print_error(E_PARSE);
	obj->vector = vec_norm(obj->vector);
	if (!lst_new_back(&(info->objects), obj))
		print_error(E_PARSE);
}

void	parse_sphere(char **buf, t_info *info)
{
	t_object	*obj;

	obj = (t_object*)ft_calloc(1, sizeof(t_object));
	if (char_arrlen(buf) != 4)
		print_error(E_PARSE);
	obj->type |= T_SPHERE;
	obj->pos[0] = parse_vector(buf[1]);
	obj->size = parse_double(buf[2]);
	obj->color = parse_color(buf[3]);
	if (!lst_new_back(&(info->objects), obj))
		print_error(E_PARSE);
}

void	parse_sqaure(char **buf, t_info *info)
{
	t_object	*obj;

	obj = (t_object*)ft_calloc(1, sizeof(t_object));
	if (char_arrlen(buf) != 5)
		print_error(E_PARSE);
	obj->type |= T_SQUARE;
	obj->pos[0] = parse_vector(buf[1]);
	obj->vector = parse_vector(buf[2]);
	obj->size = parse_double(buf[3]);
	obj->color = parse_color(buf[4]);
	if (obj->vector.x > 1 || obj->vector.x < -1 ||
		obj->vector.y > 1 || obj->vector.y < -1 ||
		obj->vector.z > 1 || obj->vector.z < -1)
		print_error(E_PARSE);
	obj->vector = vec_norm(obj->vector);
	divide_square(obj, info);
	free(obj);
}

void	parse_cylinder(char **buf, t_info *info)
{
	t_object	*obj;

	obj = (t_object*)ft_calloc(1, sizeof(t_object));
	if (char_arrlen(buf) != 6)
		print_error(E_PARSE);
	obj->type |= T_CYLINDER;
	obj->pos[0] = parse_vector(buf[1]);
	obj->vector = parse_vector(buf[2]);
	if (obj->vector.x > 1 || obj->vector.x < -1 ||
		obj->vector.y > 1 || obj->vector.y < -1 ||
		obj->vector.z > 1 || obj->vector.z < -1)
		print_error(E_PARSE);
	obj->color = parse_color(buf[3]);
	obj->vector = vec_norm(obj->vector);
	obj->size = parse_double(buf[4]);
	obj->height = parse_double(buf[5]);
	if (!lst_new_back(&(info->objects), obj))
		print_error(E_PARSE);
}

void	parse_triangle(char **buf, t_info *info)
{
	t_object	*obj;

	obj = (t_object*)ft_calloc(1, sizeof(t_object));
	if (char_arrlen(buf) != 5)
		print_error(E_PARSE);
	obj->type |= T_TRIANGLE;
	obj->pos[0] = parse_vector(buf[1]);
	obj->pos[1] = parse_vector(buf[2]);
	obj->pos[2] = parse_vector(buf[3]);
	obj->color = parse_color(buf[4]);
	if (!lst_new_back(&(info->objects), obj))
		print_error(E_PARSE);
}
