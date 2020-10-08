/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:26:55 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/08 13:59:52 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	*ft_strndup(char *s, size_t n)
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

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (!*s1 || !*s2 || *s1 != *s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
	}
	return (0);
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char *dst, char *src)
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

int		ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != (char)c)
		if (!s[i])
			return (-1);
	return (i);
}
