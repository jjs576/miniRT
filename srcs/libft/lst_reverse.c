/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:54:47 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 01:54:51 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_reverse(t_list **node)
{
	t_list	*node_cpy;
	t_list	*tmp;

	if (!node)
		return ;
	if (!*node)
		return ;
	node_cpy = *node;
	tmp = NULL;
	while (node_cpy)
	{
		tmp = node_cpy->prev;
		node_cpy->prev = node_cpy->next;
		node_cpy->next = tmp;
		node_cpy = node_cpy->prev;
	}
	*node = tmp->prev;
}
