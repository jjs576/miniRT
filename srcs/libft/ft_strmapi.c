/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:01:48 by jjoo              #+#    #+#             */
/*   Updated: 2020/07/13 14:12:03 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(ret = (char*)ft_calloc(sizeof(char), len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
