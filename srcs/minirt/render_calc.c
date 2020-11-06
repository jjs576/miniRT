/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 01:34:42 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 11:23:41 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3d		look_at(t_camera *camera, t_vec3d ray)
{
	t_matrix	matrix;
	t_vec3d		forward;
	t_vec3d		right;
	t_vec3d		up;

	forward = vec_mul(camera->vector, -1);
	right = vec_cross_prod(vec_norm(vec_new(0, 1, 0)), forward);
	up = vec_cross_prod(forward, right);
	matrix.forward = forward;
	matrix.right = right;
	matrix.up = up;
	return (mul_vec_matrix(ray, matrix));
}
