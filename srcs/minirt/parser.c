/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:28:08 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/10 17:09:48 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static BOOL	check_filename(char *file)
{
	int	i;

	i = 0;
	while (*(file + i))
		i++;
	if (i > 3 && !ft_strncmp(file + i - 3, ".rt", 3))
		return (TRUE);
	return (FALSE);
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

static void	remove_tabs(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if(line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

static void	parse_line(char *line, t_info *info)
{
	char			**buf;
	int				i;
	const t_parser	parser[] = {
		{"pl", &parse_plane}, {"sq", &parse_sqaure},
		{"sp", &parse_sphere}, {"cy", &parse_cylinder},
		{"tr", &parse_triangle}, {"R", &parse_resolution},
		{"A", &parse_ambient}, {"c", &parse_camera},
		{"l", &parse_light}
	};
	i = -1;
	remove_tabs(line);
	buf = ft_split(line, ' ');
	if (buf == 0)
		print_error(E_PARSE);
	if (!buf[0])
	{
		free_2d(buf);
		return ;
	}
	while (parser[++i].id)
		if (!ft_strcmp(buf[0], parser[i].id))
		{
			parser[i].func(buf, info);
			free_2d(buf);
			return ;
		}
	print_error(E_PARSE);
}

void		parse_file(char *file, t_info *info)
{
	int		fd;
	char	*line;
	int		ret;

	if (!check_filename(file))
		print_error(E_OPEN);
	if ((fd = open(file, O_RDONLY)) < 0)
		print_error(E_OPEN);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (line && *line != '#')
			parse_line(line, info);
		if (line)
			free(line);
	}
	if (!info->window.window_isvalid || !info->scene.ambient_isvalid)
		print_error(E_PARSE);
	if (!info->cameras || !info->lights)
		print_error(E_PARSE);
	info->cur_cam = info->cameras->content;
	close(fd);
}
