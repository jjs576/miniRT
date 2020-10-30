/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:26:20 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/30 23:24:33 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "file.h"
#include "my_mlx.h"
#include "parser.h"

t_file		*make_file(int fd)
{
	t_file	*file;

	file = (t_file*)ft_calloc(1, sizeof(t_file));
	file->fd = fd;
	return (file);
}

int			open_file(char *path)
{
	return open(path, O_RDONLY);
}

static int	get_next_line(int fd, char **line)
{
	char	*save;
	char	buf[2];
	char	*temp;
	int		flag;

	if (fd < 0 || !line)
		return R_GNL_ERROR;
	save = ft_calloc(0, 1);
	while ((flag = read(fd, buf, 1)) >= 0)
	{
		buf[flag] = 0;
		temp = save;
		save = ft_strjoin(temp, buf);
		free(temp);
		temp = 0;
		if (buf[0] == '\n' || flag == 0)
			break ;
	}
	return (flag);
}

int			read_file(t_my_mlx *mlx)
{
	int		ret;

	while ((ret = get_next_line(mlx->file->fd, &mlx->file->line)) > 0)
	{
		parse_line(mlx);
		if (mlx->file->error == TRUE)
			return (E_CANNOT_PARSE);
		free(mlx->file->line);
	}
	parse_line(mlx);
	if (ret < 0 || mlx->file->error == TRUE)
		return (E_CANNOT_PARSE);
	return (TRUE);
}

