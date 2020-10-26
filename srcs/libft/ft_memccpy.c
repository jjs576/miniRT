/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:11:47 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/06 14:35:25 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	void			*ret;

	ret = 0;
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n--)
	{
		*cdst++ = *csrc++;
		if (*(cdst - 1) == (unsigned char)c)
		{
			ret = cdst;
			break ;
		}
	}
	return (ret);
}
