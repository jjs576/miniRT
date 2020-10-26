/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:28:40 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/26 17:48:55 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

t_vec	add_vector(t_vec a, t_vec b);
t_vec	mul_vector(t_vec a, t_vec b);

#endif