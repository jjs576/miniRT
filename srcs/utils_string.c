/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:26:55 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/07 21:40:52 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
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

static void	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * n + 1)))
		return (0);
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1)
		if (*s1++ != *s2++)
			break ;
	return (*(unsigned char)s1 - *(unsigned char)s2);
}

int			ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char		*ft_strjoin(char *dst, char *src)
{
	char	*ret;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst)
		return ((ret = ft_strndup(src, src_len)));
	dst_len = ft_strlen(dst);
	if (!(ret = (char *)malloc(sizeof(char) * (dst_len + src_len + 1))))
		return (0);
	ret[0] = 0;
	ft_memcpy(ret, dst, dst_len);
	ft_memcpy(ret + dst_len, src, src_len);
	ret[dst_len + src_len] = 0;
	return (ret);
}
