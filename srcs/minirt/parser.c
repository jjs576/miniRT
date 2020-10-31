/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:28:08 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 17:40:04 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "my_mlx.h"
#include "parser.h"

void	parse_line(t_my_mlx *mlx)
{
	if (mlx->file->line[0] != 0 && mlx->file->line[0] != '#')
	{
		if (!ft_strncmp(mlx->file->line, "R", 1))
			parse_resolution(mlx);
		else if (!ft_strncmp(mlx->file->line, "sp", 2))
			parse_sphere(mlx);
		else if (!ft_strncmp(mlx->file->line, "pl", 2))
			parse_plane(mlx);
		else if (!ft_strncmp(mlx->file->line, "sq", 2))
			parse_square(mlx);
		else if (!ft_strncmp(mlx->file->line, "cy", 2))
			parse_cylinder(mlx);
		else if (!ft_strncmp(mlx->file->line, "tr", 2))
			parse_triangle(mlx);
		else if (!ft_strncmp(mlx->file->line, "A", 1))
			parse_ambient(mlx);
		else if (!ft_strncmp(mlx->file->line, "c", 1))
			parse_camera(mlx);
		else if (!ft_strncmp(mlx->file->line, "l", 1))
			parse_light(mlx);

		else
			mlx->file->error = TRUE;
	}
}

