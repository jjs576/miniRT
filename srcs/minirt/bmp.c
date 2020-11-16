/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:27:06 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/16 13:16:39 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static size_t	get_bmp_size(t_info *info)
{
	size_t	ret;

	ret = 54;
	ret += 3 * (info->window.y * ((info->window.x * 3) % 4 == 0 ?
		info->window.x : info->window.x + 4 - ((info->window.x * 3) % 4)));
	return (ret);
}

static void		bmp_file_header(char *buf, size_t file_size)
{
	*((uint8_t *)&buf[0]) = (uint8_t)0x42;
	*((uint8_t *)&buf[1]) = (uint8_t)0x4D;
	*((uint32_t *)&buf[2]) = (uint32_t)file_size;
	*((uint32_t *)&buf[10]) = (uint32_t)0x36;
}

static void		bmp_info_header(char *buf, t_info *info)
{
	*((uint32_t *)&buf[14]) = (uint32_t)0x28;
	*((uint32_t *)&buf[18]) = (uint32_t)info->window.x;
	*((uint32_t *)&buf[22]) = (uint32_t)info->window.y;
	*((uint32_t *)&buf[26]) = (uint32_t)0x01;
	*((uint32_t *)&buf[28]) = (uint32_t)0x18;
}

static void		bmp_write_image(char *buf, t_info *info)
{
	uint32_t	index;
	t_color		color;
	t_color		*image;
	int			x;
	int			y;

	index = 54;
	image = render(info);
	y = info->window.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < info->window.x)
		{
			color = image[x * info->window.y + y];
			buf[index + 0] = color.b;
			buf[index + 1] = color.g;
			buf[index + 2] = color.r;
			index += 3;
			x++;
		}
		if ((info->window.x * 3) % 4 != 0)
			index += 4 - (info->window.x * 3) % 4;
		y--;
	}
}

void			export_bmp(t_info *info)
{
	char	*buf;
	int		fd;
	size_t	file_size;

	fd = open("scene.bmp", O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		print_error(E_UNDEFINED);
	file_size = get_bmp_size(info);
	buf = ft_calloc(1, file_size);
	bmp_file_header(buf, file_size);
	bmp_info_header(buf, info);
	bmp_write_image(buf, info);
	if (write(fd, buf, file_size) < 0)
		print_error(E_UNDEFINED);
	if (close(fd) < 0)
		print_error(E_UNDEFINED);
	free(buf);
}
