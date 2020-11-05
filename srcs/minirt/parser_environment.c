/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:09:02 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 11:50:05 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			parse_resolution(char **buf, t_info *info)
{
	int	screen[2];

	if (info->window.window_isvalid)
		print_error(E_PARSE);
	if (buf[1])
		info->window.x = ft_atoi(buf[1]);
	if (buf[2])
		info->window.y = ft_atoi(buf[2]);
	if (info->window.x <= 0 || info->window.y <= 0)
		print_error(E_PARSE);
	mlx_get_screen_size(info->mlx.mlx_ptr, &screen[0], &screen[1]);
	if (info->window.x > screen[0] && !info->scene.save)
		info->window.x = screen[0];
	if (info->window.y > screen[1] && !info->scene.save)
		info->window.y = screen[1];
	info->window.window_isvalid = TRUE;
}

void			parse_ambient(char **buf, t_info *info)
{
	if (info->scene.ambient_isvalid)
		print_error(E_PARSE);

}

void			parse_camera(char **buf, t_info *info)
{

}

void			parse_light(char **buf, t_info *info)
{

}
