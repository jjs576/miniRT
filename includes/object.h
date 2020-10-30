/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:53:00 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/30 22:59:13 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef struct	s_object
{
	int		type;
	float	intensity;
	t_vec	*point;
	t_vec	*point2;
	t_vec	*point3;
	t_vec	*color;
	t_vec	*axis;
	float	size;
	float	diameter;
	float	height;
	int		fov;
}				t_object;
t_object	*make_object(int type);

#endif
