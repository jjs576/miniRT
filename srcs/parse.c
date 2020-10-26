/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:28:08 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 23:30:05 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_line(char *line, t_my_mlx *mlx)
{
	if (line[0] != 0 && line[0] != '#')
	{
		if (ft_strncmp(line, "R", 1))
			return (parse_resolution(line, mlx));
		else if (ft_strncmp(line, "A", 1))
			return (parse_ambient(line, mlx));
		else if (ft_strncmp(line, "c", 1))
			return (parse_camera(line, mlx));
		else if (ft_strncmp(line, "l", 1))
			return (parse_light(line, mlx));
		else if (ft_strncmp(line, "sp", 2))
			return (parse_sphere(line, mlx));
		else if (ft_strncmp(line, "pl", 2))
			return (parse_plane(line, mlx));
		else if (ft_strncmp(line, "sq", 2))
			return (parse_square(line, mlx));
		else if (ft_strncmp(line, "cy", 2))
			return (parse_cylinder(line, mlx));
		else if (ft_strncmp(line, "tr", 2))
			return (parse_triangle(line, mlx));
		else
			return (FALSE);
	}
	return (TRUE);
}

