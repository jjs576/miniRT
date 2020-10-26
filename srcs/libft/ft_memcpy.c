/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:57:19 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/06 20:56:41 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void		*ret;
	char		*cdst;
	const char	*csrc;

	if (!dst && !src)
		return (0);
	ret = dst;
	cdst = (char *)dst;
	csrc = (char *)src;
	while (n--)
		*cdst++ = *csrc++;
	return (ret);
}
