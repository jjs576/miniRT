/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:48:43 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/28 17:51:49 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atof(char *line, float *nb)
{
	int			i;
	int			nnb;
	float		sub_zero;

	if ((i = ft_atoi(line, &nnb)) < 0)
		return (-1);
	*nb = nnb;
	if (line[i] == '.')
		i++;
	sub_zero = (nb < 0) ? -0.1 : 0.1;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
	{
		*nb += sub_zero * (line[i++] - '0');
		sub_zero *= 0.1;
	}
	return (i);
}
