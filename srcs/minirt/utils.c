/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:49:29 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 21:43:10 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		print_error(int errno)
{
	if (errno < 0)
	{
		ft_putstr(E_MSG);
		if (errno == E_CANNOT_OPEN)
			ft_putstr(E_CANNOT_OPEN_MSG);
		else if (errno == E_CANNOT_READ)
			ft_putstr(E_CANNOT_READ_MSG);
		exit(errno);
	}
}
