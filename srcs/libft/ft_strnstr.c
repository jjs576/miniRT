/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:34:47 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/06 13:49:01 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (*(haystack + i) == *(needle + i) && (len - i))
			{
				i++;
				if (!*(needle + i))
					return ((char*)haystack);
			}
		}
		haystack++;
		len--;
	}
	return (0);
}
