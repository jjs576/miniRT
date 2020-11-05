/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:09:13 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 15:18:14 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_quaternion	quat_new(double w, double x, double y, double z)
{
	t_quaternion	ret;

	ret.w = w;
	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
