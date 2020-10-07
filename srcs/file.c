/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:24:13 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/07 20:31:03 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		read_file(t_file *file)
{
	int		buf_size;
	int		len;
	char	*buf;
	char	*temp;

	buf_size = BUF_SIZE;
	if (!(buf = (char *)malloc(sizeof(char) * buf_size + 1)))
		return (E_CANNOT_READ);
	while ((len = read(file->fd, buf, buf_size)) >= 0)
	{
		buf[len] = 0;
		temp = file->data;
		file->data = ft_strjoin(temp, buf);
		free(temp);
		temp = 0;
		if (len == 0)
			break ;
	}
	free(buf);
	buf = 0;
	if (len == -1)
		return (E_CANNOT_READ);
	return (TRUE);
}

int				open_file(t_file *file, char *filename)
{
	int	len;

	file->name = filename;
	len = ft_strlen(file->name);
	if (len > 3 && ft_strcmp(&(file->name[len - 3]), ".rt"))
		return (E_WRONG_FILENAME);
	if ((file->fd = open(file->name, 0_RDONLY)) <= 0)
		return (E_CANNOT_OPEN);
	return (read_file(file));
}
