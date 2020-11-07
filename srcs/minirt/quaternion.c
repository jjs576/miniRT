/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:09:13 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/07 17:18:23 by jjoo             ###   ########.fr       */
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

t_quaternion	quat_norm(t_quaternion quat)
{
	t_quaternion	new;
	double			mag;

	mag = sqrt(pow(quat.w, 2) + pow(quat.x, 2) + pow(quat.y, 2) +
		pow(quat.z, 2));
	new.w = quat.w / mag;
	new.x = quat.x / mag;
	new.y = quat.y / mag;
	new.z = quat.z / mag;
	return (new);
}

t_quaternion	quat_local_rot(t_vec3d axis, double angle)
{
	return (quat_new(cos(angle / 2),
			axis.x * sin(angle / 2),
			axis.y * sin(angle / 2),
			axis.z * sin(angle / 2)));
}

t_quaternion	quat_multi(t_quaternion q1, t_quaternion q2)
{
	t_quaternion ret;

	ret.w = ((q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z));
	ret.x = ((q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y));
	ret.y = ((q1.w * q2.y) - (q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x));
	ret.z = ((q1.w * q2.z) + (q1.x * q2.y) - (q1.y * q2.x) + (q1.z * q2.w));
	return (ret);
}

t_quaternion	rotate_cam(t_vec3d vector, t_vec3d axis, double angle)
{
	t_quaternion	p[2];
	t_quaternion	r[2];

	p[0] = quat_new(0, vector.x, vector.y, vector.z);
	r[0] = quat_local_rot(axis, angle);
	r[1] = quat_new(r[0].w, -r[0].x, -r[0].y, -r[0].z);
	p[1] = quat_multi(quat_multi(r[0], p[0]), r[1]);
	return (p[1]);
}
