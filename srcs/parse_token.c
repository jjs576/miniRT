/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:13:49 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/28 23:41:49 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_space(char *line)
{
	int	count;

	if (!ft_isspace(*line))
		return (-1);
	count = 0;
	while (ft_isspace(*(line + count)))
		count++;
	return (count);
}

int		parse_int(char *line, int *dst)
{
	int	count;

	if ((count = ft_atoi(line, dst)) < 0)
		return (-1);
	return (count);
}

int		parse_float(char *line, float *dst)
{
	int	count;

	if ((count = ft_atof(line, dst)) < 0)
		return (-1);
	return (count);
}

int		parse_multi_int(char *line, int **dst)
{
	int	count;
	int	ret;
	int i;

	count = 0;
	i = 0;
	while (i < 3)
	{
		if ((ret = ft_atoi(line, dst[i])) < 0)
			return (-1);
		count += ret;
		if (*(line + count) == ',')
			count++;
		else
			return (-1);
		i++;
	}
}

int		parse_multi_float(char *line, float **dst)
{
	int	count;
	int	ret;
	int i;

	count = 0;
	i = 0;
	while (i < 3)
	{
		if ((ret = ft_atof(line, dst[i])) < 0)
			return (-1);
		count += ret;
		if (*(line + count) == ',')
			count++;
		else
			return (-1);
		i++;
	}
}
