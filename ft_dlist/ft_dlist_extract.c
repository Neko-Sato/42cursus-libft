/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 05:10:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 10:32:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

t_dlist_node	*ft_dlist_extract(t_dlist *dlist, t_dlist_node *pos)
{
	t_dlist_node	*tmp;

	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	tmp = pos->_next;
	pos->_next = NULL;
	pos->_prev = NULL;
	dlist->_size--;
	return (tmp);
}
