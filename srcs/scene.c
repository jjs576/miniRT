/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:25:35 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/28 23:32:45 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*make_scene()
{
	t_scene	*s;

	s = (t_scene*)ft_calloc(1, sizeof(t_scene));
	s->lights = (t_object*)ft_calloc(MAX_OBJECT, sizeof(t_object));
	s->objects = (t_object*)ft_calloc(MAX_OBJECT, sizeof(t_object));
	return (s);
}
