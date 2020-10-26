/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:44:53 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/06 13:30:42 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (0);
	cdst = (char *)dst;
	csrc = (char *)src;
	if (csrc < cdst)
		while ((int)--len >= 0)
			*(cdst + len) = *(csrc + len);
	else
		while (++i < len)
			*(cdst + i) = *(csrc + i);
	return (dst);
}
