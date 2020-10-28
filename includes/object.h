/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:53:00 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/28 23:36:15 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"

typedef struct	s_object
{
	int		type;
	float	intensity;
	t_vec	point;
	t_vec	color;

}				t_object;

#endif
