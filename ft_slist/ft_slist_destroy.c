/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:58:25 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:02:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

void	ft_slist_destroy(t_slist *slist)
{
	t_slist_node	*tmp;

	while (1)
	{
		tmp = slist->_head;
		if (!tmp)
			break ;
		slist->_head = tmp->next;
		slist->_size--;
		ft_slist_node_delete(tmp);
	}
}
