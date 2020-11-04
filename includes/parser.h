/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:57:15 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/04 19:55:33 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "my_mlx.h"

/*
**	parser
*/

void	parse_line(t_my_mlx *mlx);

/*
**	parser_environment
*/

void	parse_resolution(t_my_mlx *mlx);
void	parse_ambient(t_my_mlx *mlx);
void	parse_camera(t_my_mlx *mlx);
void	parse_light(t_my_mlx *mlx);

/*
**	parser_object
*/

void	parse_sphere(t_my_mlx *mlx);
void	parse_plane(t_my_mlx *mlx);
void	parse_square(t_my_mlx *mlx);
void	parse_cylinder(t_my_mlx *mlx);
void	parse_triangle(t_my_mlx *mlx);

/*
**	parser_token
*/

void	parse_space(t_my_mlx *mlx);
int		parse_int(t_my_mlx *mlx);
float	parse_float(t_my_mlx *mlx);
int		*parse_multi_int(t_my_mlx *mlx);
float	*parse_multi_float(t_my_mlx *mlx);

#endif
