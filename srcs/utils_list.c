/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 14:55:28 by jjoo              #+#    #+#             */
/*   Updated: 2020/10/08 16:14:47 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list	*new_object(int type, void *object)
{
	t_list	*obj;

	if (!(obj = malloc(sizeof(t_list))))
		check_error(E_MALLOC_FAIL);
	obj->type = type;
	obj->data = object;
	obj->next = NULL;
	return (obj);
}

int		push_back(t_list **lst, int type, void *object)
{
	t_list *begin;

	if (!lst)
		return (-1);
	begin = *lst;
	if (begin)
	{
		while (begin->next)
			begin = begin->next;
		if (!(begin->next = new_object(type, object)))
			return (-1);
	}
	else
	{
		*lst = new_object(type, object);
		begin = *lst;
	}
	return (0);
}

t_list	*copy_list(t_list *lst)
{
	return (new_object(lst->type, lst->data));
}
