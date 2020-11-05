/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:53:10 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 01:53:50 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_new_back(t_list **node, void *content)
{
	t_list	*new;
	t_list	*node_cpy;

	if (!node)
		return (NULL);
	if (!*node)
	{
		*node = lst_new(content);
		return (*node);
	}
	node_cpy = *node;
	while (node_cpy->next)
		node_cpy = node_cpy->next;
	new = lst_new(content);
	new->prev = node_cpy;
	node_cpy->next = new;
	return (new);
}
