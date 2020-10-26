/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:49:29 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 18:07:14 by jjoo             ###   ########.fr       */
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
	char	*line;
	char	buf[2];
	int		flag;

	if (fd == -1)
		return E_CANNOT_OPEN;
	while ((flag = read(fd, buf, 1) >= 0)
	{
		buf[1] = 0;

	}
}

int			read_file(int fd, t_my_mlx *mlx)
{



}

