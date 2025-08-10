/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_erase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:10:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:10:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

void	ft_slist_erase(t_slist *slist, t_slist_node *pos)
{
	t_slist_node	*current;

	current = slist->_head;
	while (current->next != pos)
		current = current->next;
	current->next = pos->next;
	slist->_size--;
	ft_slist_node_delete(pos);
}
