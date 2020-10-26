/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:57:17 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/09 16:50:39 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	if (start > end)
	{
		if (!(ret = ft_calloc(sizeof(char), 1)))
			return (0);
		return (ret);
	}
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	if (!(ret = ft_calloc(sizeof(char), end - start + 2)))
		return (0);
	ft_strlcpy(ret, s1 + start, end - start + 2);
	return (ret);
}
