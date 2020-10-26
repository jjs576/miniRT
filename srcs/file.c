/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:26:20 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 21:49:20 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int			read_file(int fd, t_my_mlx *mlx)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if ((ret = parse_line(line, mlx)) == FALSE)
			return (E_CANNOT_PARSE);
		free(line);
	}
	if (ret < 0 || (ret = parse_line(line, mlx)) == FALSE)
		return (E_CANNOT_PARSE);
	return (TRUE);
}

