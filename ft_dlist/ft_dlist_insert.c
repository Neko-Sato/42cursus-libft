/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:04:37 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/20 00:15:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

void	ft_dlist_insert(t_dlist *dlist, t_dlist_node *pos, t_dlist_node *node)
{
	node->_next = pos;
	if (pos)
	{
		node->_prev = pos->_prev;
		pos->_prev = node;
	}
	else
	{
		node->_prev = dlist->_tail;
		dlist->_tail = node;
	}
	if (node->_prev)
		node->_prev->_next = node;
	else
		dlist->_head = node;
	dlist->_size++;
}
