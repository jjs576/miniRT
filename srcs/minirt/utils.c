/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:49:29 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 21:12:51 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int errno)
{
	const t_error	error[] = {
		{E_UNDEFINED, E_UNDEFINED_MSG},
		{E_ARGUMENTS, E_ARGUMENTS_MSG},
		{E_OPEN, E_OPEN_MSG},
		{E_READ, E_READ_MSG},
		{E_PARSE, E_PARSE_MSG},
		{E_MALLOC, E_MALLOC_MSG},
		{E_THREAD, E_THREAD_MSG},
		{E_MUTEX, E_MUTEX_MSG}
	};
	ft_putstr(E_MSG);
	ft_putstr(error[errno].msg);
	exit(errno);
}

void	exit_free(t_info *info)
{
	free_info(info);
	exit(1);
}

int		exit_mlx(void)
{
	exit(0);
	return (0);
}
