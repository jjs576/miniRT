/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:49:29 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 18:32:09 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		print_error(int errno)
{
	if (errno == E_CANNOT_OPEN)
		ft_putstr(E_CANNOT_OPEN_MSG);
	else if (errno == E_CANNOT_READ)
		ft_putstr(E_CANNOT_READ_MSG);
	if (errno < 0)
		exit(errno);
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
		if (flag == 0)
			break ;
	}
	return (flag);
}

int			read_file(int fd, t_my_mlx *mlx)
{



}

