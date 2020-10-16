/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/16 15:51:44 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_window(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
	mlx->mlx_img, 0, 0);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_scene	scene;
	t_file	file;
	t_mlx	*mlx;

	if (argc != 2 && argc != 3)
		check_error(-1);
	ft_memset(&file, 0, sizeof(t_file));
	check_error(open_file(&file, argv[1]));
	check_error(parser(&file, &scene));
	close(file.fd);
	mlx = init_mlx(&scene);
	//create_image(&mlx);
	// make image
	if (argc == 2)
		start_window(mlx);
	else if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
	{
		;
	}
	else
		check_error(-1);
	return (0);
}
