/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:27:03 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/06 13:40:42 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	char	*csrc;
	char	*cdst;

	if (!dst || !src)
		return (0);
	csrc = (char *)src;
	cdst = (char *)dst;
	ret = ft_strlen(csrc);
	if (dstsize)
	{
		while (*csrc && dstsize-- > 1)
			*cdst++ = *csrc++;
		*cdst = 0;
	}
	return (ret);
}
