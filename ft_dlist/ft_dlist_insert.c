/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:04:37 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:37:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

void	ft_dlist_insert(t_dlist *dlist, t_dlist_node *pos, t_dlist_node *node)
{
	node->prev = pos->prev;
	node->next = pos->next;
	if (pos->prev)
		pos->prev->next = node;
	else
		dlist->_head = node;
	if (pos->next)
		pos->next->prev = node;
	else
		dlist->_tail = node;
	dlist->_size++;
}
