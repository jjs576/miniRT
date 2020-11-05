/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:49 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 13:32:50 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	parse_double(char *str)
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

t_vec3d		parse_coord(char *str)
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
