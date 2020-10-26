/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:05:45 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/02 09:51:15 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(dst);
	len = (len < dstsize ? len : dstsize);
	if (len == dstsize)
		return (dstsize + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, dstsize - len));
}
