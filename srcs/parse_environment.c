/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:09:02 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/28 23:41:46 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int		parse_resolution(char *line, t_my_mlx *mlx)
{
	int	i;
	int	r;

	i = 1;
	if ((r = parse_space(line + i)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_int(line + i, &mlx->scene->width)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_space(line + i)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_int(line + i, &mlx->scene->height)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_space(line + i)) < 0 && (i += r) > 0)
		return (FALSE);
	if (*(line + i) != 0)
		return (FALSE);
	return (TRUE);
}

int		parse_ambient(char *line, t_my_mlx *mlx)
{

	int		i;
	int		r;

	i = 1;
	if ((r = parse_space(line + i)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_float(line + i, &intensity)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_space(line + i)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_multi_int(line + i, &mlx->scene->height)) < 0 && (i += r) > 0)
		return (FALSE);
	if ((r = parse_space(line + i)) < 0 && (i += r) > 0)
		return (FALSE);
	if (*(line + i) != 0)
		return (FALSE);
	return (TRUE);
}

int		parse_camera(char *line, t_my_mlx *mlx)
{

}

int		parse_light(char *line, t_my_mlx *mlx)
{

}
