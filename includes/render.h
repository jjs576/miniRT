/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:25:20 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/03 09:05:05 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "thread.h"

void	render_pixel(t_thread_info *data, int y, int color);
void	render(t_object *cam, t_my_mlx *mlx);

#endif
