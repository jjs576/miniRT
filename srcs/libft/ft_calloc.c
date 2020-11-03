/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:22:37 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/03 08:46:25 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (!(ret = malloc(size * count)))
		print_error(E_MALLOC_FAIL);
	ft_memset(ret, 0, size * count);
	return (ret);
}
