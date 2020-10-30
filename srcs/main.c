/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:21:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/30 23:11:50 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "my_mlx.h"

int		main(int argc, char **argv)
{
	int		err;
	t_my_mlx mlx;

	if (argc != 2 && argc != 3)
		print_error(E_ARGUMENTS);
	mlx.file = make_file(open_file(argv[1]));
	print_error(read_file(&mlx));
	return (0);
}
