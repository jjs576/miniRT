/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:49 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 17:35:38 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	parse_space(t_my_mlx *mlx)
{
	while (ft_isspace(*(mlx->file->line + mlx->file->index)))
		mlx->file->index++;
}

int		parse_int(t_my_mlx *mlx)
{
	int	ret;

	ret = ft_atoi(mlx->file->line + mlx->file->index);
	if (*(mlx->file->line + mlx->file->index) == '-')
		mlx->file->index++;
	while (ft_isdigit(*(mlx->file->line + mlx->file->index)))
		mlx->file->index++;
	return (ret);
}

float	parse_float(t_my_mlx *mlx)
{
	int		num1;
	float	num2;
	int		xindex;
	float	ret;

	num1 = parse_int(mlx);
	if (*(mlx->file->line + mlx->file->index) == '.'){
		mlx->file->index++;
		xindex = mlx->file->index;
		num2 = parse_int(mlx);
		while (xindex--)
			num2 *= 0.1;
	}
	else
		num2 = 0;
	if (num1 >= 0)
		ret = (float)num1 + num2;
	else
		ret = (float)num1 - num2;
	return (ret);
}

float	*parse_multi_float(t_my_mlx *mlx)
{
	float	*ret;

	ret = ft_calloc(3, sizeof(float));
	ret[0] = parse_float(mlx);
	if (*(mlx->file->line + mlx->file->index) != ',')
		mlx->file->error = TRUE;
	mlx->file->index++;
	ret[1] = parse_float(mlx);
	if (*(mlx->file->line + mlx->file->index) != ',')
		mlx->file->error = TRUE;
	mlx->file->index++;
	ret[2] = parse_float(mlx);
	return (ret);
}
