/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 20:00:37 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **argv)
{
	t_info info;

	ft_bzero(&info, sizeof(t_info));
	if (argc != 2 && argc != 3)
		print_error(E_ARGUMENTS);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 6))
			info.scene.save = TRUE;
		else
			print_error(E_ARGUMENTS);
	}
	parse_file(argv[1], &info);
	if (!info.cameras->content)
		print_error(E_UNDEFINED);
	info.cur_cam = info.cameras->content;
	if (info.scene.save)
	{
		export_bmp(&info);
		exit_free(&info);
	}
	if (!init(&info))
		print_error(E_UNDEFINED);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
