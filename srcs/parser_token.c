/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:49 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/31 01:40:10 by jjoo             ###   ########.fr       */
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

	if (*mlx->file->line == '-')
		mlx->file->index++;
	while (ft_isdigit(*(mlx->file->line + mlx->file->index)))
		mlx->file->index++;
	ret = ft_atoi(mlx->file->line);
	return (ret);
}

float	parse_float(t_my_mlx *mlx)
{

}

int		*parse_multi_int(t_my_mlx *mlx)
{

}

float	*parse_multi_float(t_my_mlx *mlx)
{

}
