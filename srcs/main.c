/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/07 20:47:47 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **argv)
{
	t_rt	rt;
	t_file	file;
	t_mlx	mlx;

	if (argc != 2 && argc != 3)
		print_error(-1);
	check_error(open_file(&file, argv[1]));
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		//safve
	}
	return (0);
}
