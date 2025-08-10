/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:10:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:40:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

void	ft_dlist_erase(t_dlist *dlist, t_dlist_node *pos)
{
	if (pos->prev)
		pos->prev->next = pos->next;
	else
		dlist->_head = pos->next;
	if (pos->next)
		pos->next->prev = pos->prev;
	else
		dlist->_tail = pos->prev;
	ft_dlist_node_delete(pos);
	dlist->_size--;
}
