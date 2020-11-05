/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:53:37 by jjoo              #+#    #+#             */
/*   Updated: 2020/11/05 01:53:44 by jjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_new_front(t_list **node, void *content)
{
	t_list	*new;

	if (!node)
		return ;
	if (!*node)
	{
		*node = lst_new(content);
		return ;
	}
	new = lst_new(content);
	new->next = *node;
	(*node)->prev = new;
	*node = new;
}
