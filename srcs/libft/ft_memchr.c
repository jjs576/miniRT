/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:55:05 by jjoo              #+#    #+#             */
/*   Updated: 2020/06/30 16:10:05 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
		if (*cs++ == cc)
			return (cs - 1);
	return (0);
}
