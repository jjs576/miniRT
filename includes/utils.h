/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 11:25:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 17:46:33 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "my_mlx.h"

void			print_error(int errno);

int				open_file(char *path);
int				read_file(int fd, t_my_mlx *mlx);

#endif
