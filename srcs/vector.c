/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:04:26 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/30 23:13:59 by jjoo             ###   ########.fr       */
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

t_vec	add_vector(t_vec a, t_vec b)
{

}

t_vec	mul_vector(t_vec a, t_vec b)
{

}
