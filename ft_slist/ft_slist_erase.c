/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:10:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 21:09:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

t_slist_node	*ft_slist_erase(t_slist *slist, t_slist_node *pos)
{
	t_slist_node	**current;

	current = &slist->_head;
	while (*current != pos)
		current = &(*current)->_next;
	*current = pos->_next;
	ft_slist_node_delete(pos);
	slist->_size--;
	return (*current);
}
