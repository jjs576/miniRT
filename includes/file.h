/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:53:24 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/30 23:22:37 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "my_mlx.h"

typedef struct	s_file
{
	int		fd;
	char	*line;
	int		index;
	int		error;
}				t_file;

t_file		*make_file(int fd);
int			open_file(char *path);
int			read_file(t_my_mlx *mlx);

#endif
