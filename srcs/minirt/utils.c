/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:49:29 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/16 14:44:56 by jjoo             ###   ########.fr       */
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

void	exit_mlx(int keycode, t_info *info)
{
	(void)keycode;
	mlx_destroy_window(info->mlx.mlx_ptr, info->mlx.win_ptr);
	exit_free(info);
}

void	swap_double(double *d1, double *d2)
{
	double temp;

	temp = *d1;
	*d1 = *d2;
	*d2 = temp;
}

size_t	char_arrlen(char **array)
{
	size_t	res;

	res = 0;
	while (array[res])
		res++;
	return (res);
}
