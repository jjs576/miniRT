/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:28:53 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 21:30:27 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_matrix	matrix_new(t_vec3d vec)
{
	t_matrix	matrix;

	matrix.forward = vec_mul(vec, -1);
	matrix.right = vec_cross_prod(vec_norm(vec_new(0, 1, 0)),
					matrix.forward);
	matrix.up = vec_cross_prod(matrix.forward, matrix.right);
	matrix_norm(matrix);
	return (matrix);
}

t_matrix	matrix_norm(t_matrix matrix)
{
	t_matrix res;

	res.forward = vec_norm(matrix.forward);
	res.right = vec_norm(matrix.right);
	res.up = vec_norm(matrix.up);
	return (res);
}
