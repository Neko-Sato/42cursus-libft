/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:04:37 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:27:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

void	ft_slist_insert(t_slist *slist, t_slist_node *pos, t_slist_node *node)
{
	t_slist_node	*current;

	current = slist->_head;
	while (current->_next != pos)
		current = current->_next;
	current->_next = node;
	node->_next = pos->_next;
	slist->_size++;
}
