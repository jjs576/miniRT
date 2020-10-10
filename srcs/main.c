/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/10 17:51:23 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **argv)
{
	t_scene	scene;
	t_file	file;
	t_mlx	mlx;

	if (argc != 2 && argc != 3)
		check_error(-1);
	ft_memset(&file, 0, sizeof(t_file));
	check_error(open_file(&file, argv[1]));
	check_error(parser(&file, &scene));
	close(file.fd);
	init_mlx(&mlx, &scene);
	create_image(&mlx);
	// make image
	if (argc == 2)
		;
	else if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		;
	}
	else
		check_error(-1);
	return (0);
}
