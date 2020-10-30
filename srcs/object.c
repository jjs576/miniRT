/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:36:03 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/30 23:26:37 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"

t_object	*make_object(int type)
{
	t_object	*object;

	object = (t_object*)ft_calloc(1, sizeof(t_object));
	return (object);
}
