/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:24:55 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 23:25:04 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	i = 0;
	if (!(dup = ft_calloc(sizeof(char), n + 1)))
		return (0);
	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
