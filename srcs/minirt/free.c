/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:02:23 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/06 21:25:33 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_list(t_list *list, void (*func)(void *))
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		func(list->content);
		free(list);
		list = temp;
	}
}

void	free_info(t_info *info)
{
	if (info->objects)
		free_list(info->objects, &free);
	if (info->cameras)
		free_list(info->cameras, &free);
	if (info->lights)
		free_list(info->lights, &free);
}

void	free_2d(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
