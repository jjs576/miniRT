/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:49 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 21:27:42 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_square_corner(t_object *sq, t_vec3d *corners)
{
	t_matrix	sq_matrix;
	t_vec3d		corner_vec[2];

	if (sq->vector.x == 0 && (sq->vector.y == 1 || sq->vector.y == -1)
		&& sq->vector.z == 0)
	{
		sq_matrix.forward = vec_new(0,sq->vector.y == 1 ? 1 : -1, 0);
		sq_matrix.right = vec_new(1, 0, 0);
		sq_matrix.up = vec_new(0, 0, 1);
	}
	else
		sq_matrix = matrix_new(sq->vector);
	corner_vec[0] = vec_mul(sq_matrix.up, 0.5 * sq->size);
	corner_vec[1] = vec_mul(sq_matrix.right, 0.5 * sq->size);
	corners[0] = vec_add(sq->pos[0], vec_add(corner_vec[0], corner_vec[1]));
	corners[1] = vec_add(sq->pos[0], vec_sub(corner_vec[0], corner_vec[1]));
	corners[2] = vec_sub(sq->pos[0], vec_add(corner_vec[0], corner_vec[1]));
	corners[3] = vec_sub(sq->pos[0], vec_sub(corner_vec[0], corner_vec[1]));
}

void		divide_square(t_object *sq, t_info *info)
{
	t_object	*tri[2];
	t_vec3d		corners[4];

	tri[0] = (t_object*)ft_calloc(1, sizeof(t_object));
	tri[1] = (t_object*)ft_calloc(1, sizeof(t_object));
	get_square_corner(sq, corners);
	tri[0]->type |= T_TRIANGLE;
	tri[0]->pos[0] = corners[0];
	tri[0]->pos[1] = corners[1];
	tri[0]->pos[2] = corners[2];
	tri[0]->color = sq->color;
	tri[1]->type |= T_TRIANGLE;
	tri[1]->pos[0] = corners[1];
	tri[1]->pos[1] = corners[2];
	tri[1]->pos[2] = corners[3];
	tri[1]->color = sq->color;
	if (!lst_new_back(&(info->objects), tri[0]) ||
		!lst_new_back(&(info->objects), tri[1]))
		print_error(E_PARSE);
}

double		parse_double(char *str)
{
	double	res;
	int		count;
	BOOL	is_neg;

	res = ft_atoi(str);
	is_neg = FALSE;
	if (res < 0 || *str == '-')
	{
		str++;
		is_neg = TRUE;
	}
	while (ft_isdigit(*str))
		str++;
	count = 1;
	if (*str != '.')
		return (res);
	str++;
	while (ft_isdigit(*str))
	{
		res += (((int)(*str - '0')) / pow(10, count) * (is_neg ? -1 : 1));
		count++;
		str++;
	}
	return (res);
}

t_vec3d		parse_vector(char *str)
{
	t_vec3d	coord;
	char	**values;

	values = ft_split(str, ',');
	coord.x = parse_double(values[0]);
	coord.y = parse_double(values[1]);
	coord.z = parse_double(values[2]);
	free_2d(values);
	return (coord);
}

t_color		parse_color(char *str)
{
	char	**rgb;
	double	c[3];

	rgb = ft_split(str, ',');
	c[0] = parse_double(rgb[0]);
	c[1] = parse_double(rgb[1]);
	c[2] = parse_double(rgb[2]);
	if ((c[0] > 255 || c[0] < 0) ||
		(c[1] > 255 || c[1] < 0) ||
		(c[2] > 255 || c[2] < 0))
		print_error(E_PARSE);
	free_2d(rgb);
	return (color_new(c[0], c[1], c[2]));
}
