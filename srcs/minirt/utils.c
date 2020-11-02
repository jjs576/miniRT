/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:49:29 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/02 15:33:20 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int errno)
{
	if (errno < 0)
	{
		ft_putstr(E_MSG);
		if (errno == E_CANNOT_OPEN)
			ft_putstr(E_CANNOT_OPEN_MSG);
		else if (errno == E_CANNOT_READ)
			ft_putstr(E_CANNOT_READ_MSG);
		else if (errno == E_ARGUMENTS)
			ft_putstr(E_ARGUMENTS_MSG);
		else if (errno == E_CANNOT_PARSE)
			ft_putstr(E_CANNOT_PARSE_MSG);
		else if (errno == E_MALLOC_FAIL)
			ft_putstr(E_MALLOC_FAIL_MSG);
		else if (errno == E_MUTEX_INIT)
			ft_putstr(E_MUTEX_INIT_MSG);
		exit(errno);
	}
}

int		exit_mlx(void)
{
	exit(0);
	return (0);
}
