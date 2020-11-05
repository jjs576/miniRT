/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 09:35:05 by jjoo             ###   ########.fr       */
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
}
