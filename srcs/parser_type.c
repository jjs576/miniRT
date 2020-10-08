/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:59:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/08 14:25:59 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	parse_double(char *s, double *dst)
{

}

int		parse_multi_double(char	*s, double *dst)
{

}

int		parse_int(char *s, int *dst)
{

}

int		parse_multi_int(char *s, int *dst)
{

}

int		parse_space(char *s)
{
	int	count;

	count = 0;
	while (ft_strchr(" \t\r\f\v", *s++) > -1)
		count++;
	return (count);
}
