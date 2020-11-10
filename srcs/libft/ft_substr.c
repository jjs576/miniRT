/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:36:52 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/06 20:57:01 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*ret;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > len)
	{
		if (!(ret = ft_calloc(sizeof(char), 1)))
			return (0);
		return (ret);
	}
	while (s[i + start] && i < len)
		i++;
	if (!(ret = ft_calloc(sizeof(char), i + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	return (ret);
}
