/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:26:20 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/03 08:48:14 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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
	char	buf[1];
	char	*save;
	int		count;
	int		flag;
	char	*temp;

	if (!line)
		return -1;
	save = ft_calloc(10000, sizeof(char));
	count = 0;
	while ((flag = read(fd, buf, 1)) >= 0)
	{
		if (buf[0] == '\n' || flag == 0)
			break ;
		save[count++] = buf[0];
		save[count] = 0;
	}
	temp = ft_calloc(count + 1, sizeof(char));
	ft_memcpy(temp, save, count);
	temp[count] = 0;
	*line = temp;
	free(save);
	return (flag);
}

int			read_file(t_my_mlx *mlx)
{
	int		ret;

	mlx->file->line = 0;
	while ((ret = get_next_line(mlx->file->fd, &mlx->file->line)) > 0)
	{
		mlx->file->index = 0;
		parse_line(mlx);
		ft_putendl(mlx->file->line);
		if (mlx->file->error == TRUE)
			return (E_CANNOT_PARSE);
		free(mlx->file->line);
		mlx->file->line = 0;
	}
	parse_line(mlx);
	if (ret < 0 || mlx->file->error == TRUE)
		return (E_CANNOT_PARSE);
	return (TRUE);
}
