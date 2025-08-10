/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:58:25 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:21:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

void	ft_dlist_destroy(t_dlist *dlist)
{
	t_dlist_node	*tmp;

	while (1)
	{
		tmp = dlist->_head;
		if (!tmp)
			break ;
		dlist->_head = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		dlist->_size--;
		ft_dlist_node_delete(tmp);
	}
}
