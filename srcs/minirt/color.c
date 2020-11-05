/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:06:24 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 19:58:48 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color			color_new(int r, int g, int b)
{
	t_color	ret;

	ret.r = r;
	ret.g = g;
	ret.b = b;
	return (ret);
}

t_color			color_mix(t_color c1, t_color c2)
{
	return (color_new((c1.r + c2.r) / 2,
		(c1.g + c2.g) / 2, (c1.b + c2.b) / 2));
}

t_color			color_mul(t_color c, double f)
{
	return (color_new(fmin(c.r * f, 255.0),
			fmin(c.g * f, 255.0),
			fmin(c.b * f, 255.0)));
}

t_color			color_add(t_color c1, t_color c2)
{
	return (color_new(fmax(c1.r, c2.r), fmax(c1.g, c2.g), fmax(c1.b, c2.b)));
}

t_color			color_mix_light(t_color c, t_color l)
{
	return (color_new(c.r * l.r / 255, c.g * l.g / 255, c.b * l.b / 255));
}
