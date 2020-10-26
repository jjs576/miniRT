/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:29:14 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 23:28:03 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "libft.h"
# include "mlx.h"
# include "vector.h"
# include "const.h"
# include "object.h"
# include "my_mlx.h"

/*
**	parse
*/

int		parse_line(char *line, t_my_mlx *mlx);

/*
**	parse_environment
*/

int		parse_resolution(char *line, t_my_mlx *mlx);
int		parse_ambient(char *line, t_my_mlx *mlx);
int		parse_camera(char *line, t_my_mlx *mlx);
int		parse_light(char *line, t_my_mlx *mlx);

/*
**	parse_object
*/

int		parse_sphere(char *line, t_my_mlx *mlx);
int		parse_plane(char *line, t_my_mlx *mlx);
int		parse_square(char *line, t_my_mlx *mlx);
int		parse_cylinder(char *line, t_my_mlx *mlx);
int		parse_triangle(char *line, t_my_mlx *mlx);

/*
**	parse_token
*/

int		parse_space(char *line, t_my_mlx *mlx);
int		parse_int(char *line, t_my_mlx *mlx);
int		parse_float(char *line, t_my_mlx *mlx);
int		parse_multi_int(char *line, t_my_mlx *mlx);
int		parse_multi_float(char *line, t_my_mlx *mlx);



/*
**	utils
*/

void	print_error(int errno);

/*
**	file
*/

int		open_file(char *path);
int		read_file(int fd, t_my_mlx *mlx);

#endif
