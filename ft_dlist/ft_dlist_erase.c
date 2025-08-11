/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:10:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:41:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

t_dlist_node	*ft_dlist_erase(t_dlist *dlist, t_dlist_node *pos)
{
	t_dlist_node	*tmp;

	if (pos->_prev)
		pos->_prev->_next = pos->_next;
	else
		dlist->_head = pos->_next;
	if (pos->_next)
		pos->_next->_prev = pos->_prev;
	else
		dlist->_tail = pos->_prev;
	tmp = pos->_next;
	ft_dlist_node_delete(pos);
	dlist->_size--;
	return (tmp);
}
