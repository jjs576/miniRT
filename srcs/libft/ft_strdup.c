/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:26:38 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 23:24:23 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memcpy(ret, s1, len);
	ret[len] = 0;
	return (ret);
}
