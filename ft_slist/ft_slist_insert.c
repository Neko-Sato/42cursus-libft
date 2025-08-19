/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:04:37 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 21:09:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

void	ft_slist_insert(t_slist *slist, t_slist_node *pos, t_slist_node *node)
{
	t_slist_node	**current;

	current = &slist->_head;
	while (*current != pos)
		current = &(*current)->_next;
	*current = node;
	node->_next = pos;
	slist->_size++;
}
