/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:51:43 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/08 13:38:49 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_error(int n)
{
	if (n > 0)
		return;
	ft_putstr("Error\n");
	exit(n);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret;
	char	*src_char;
	char	*dst_char;

	if (!dst && !src)
		return (0);
	ret = dst;
	dst_char = (char *)dst;
	src_char = (char *)src;
	while (n--)
		*dst_char++ = *src_char++;
	return (ret);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*uc;

	uc = b;
	while (len > 0)
	{
		*uc++ = (unsigned char)c;
		len--;
	}
	return (b);
}
