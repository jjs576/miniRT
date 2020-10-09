/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/09 10:43:07 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **argv)
{
	t_scene	scene;
	t_file	file;
	t_mlx	mlx;

	if (argc != 2 && argc != 3)
		print_error(-1);
	ft_memset(&file, 0, sizeof(t_file));
	check_error(open_file(&file, argv[1]));
	check_error(parser(&file, &scene));
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		;
	}
	return (0);
}
