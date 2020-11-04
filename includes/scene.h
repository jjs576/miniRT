/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:17:22 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/04 16:59:28 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include "object.h"

typedef struct	s_scene
{
	int			width;
	int			height;
	float		total_intensity;
	int			num_light;
	int			num_object;
	int			num_camera;
	int			cur_camera;
	int			*queue;
	int			q_size;
	t_object	*lights;
	t_object	*objects;
	t_object	*cameras;
}				t_scene;

t_scene		*make_scene();
t_scene		*copy_scene(t_scene *origin);
#endif
