/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:04:26 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/04 19:35:50 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vector.h"

t_vec	*make_vector(float data[3])
{
	t_vec	*vec;

	vec = (t_vec*)ft_calloc(1, sizeof(t_vec));
	vec->x = data[0];
	vec->y = data[1];
	vec->z = data[2];
	return (vec);
}

t_vec	*make_vector_zero()
{
	const float	data[3] = {0, 0, 0};

	return (make_vector(data));
}
