/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:45:54 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/09 11:57:16 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_line(char *str, t_scene *scene)
{
	if (!ft_strncmp(str, "R", 1))
		return (parse_resolution(str, scene));
	else if (!ft_strncmp(str, "A", 1))
		return (parse_ambient(str, scene));
	else if (!ft_strncmp(str, "c", 1))
		return (parse_camera(str, scene));
	else if (!ft_strncmp(str, "l", 1))
		return (parse_light(str, scene));
	else if (!ft_strncmp(str, "sp", 2))
		return (parse_sphere(str, scene));
	else if (!ft_strncmp(str, "pl", 2))
		return (parse_plane(str, scene));
	else if (!ft_strncmp(str, "sq", 2))
		return (parse_square(str, scene));
	else if (!ft_strncmp(str, "cy", 2))
		return (parse_cylinder(str, scene));
	else if (!ft_strncmp(str, "tr", 2))
		return (parse_triangle(str, scene));
	else if (!ft_strncmp(str, "\n", 1))
		return (1);
	else
		return (-1);
}

int			parser(t_file *f, t_scene *s)
{
	char	*ptr;
	int		count;

	ptr = *f->data;
	if (ptr == 0)
		return (E_INVALID_FILE);
	while (*ptr)
	{
		if ((count = parse_line(ptr, s)) == -1)
			return (E_INVALID_FILE);
		ptr += count;
	}
	return (TRUE);
}
