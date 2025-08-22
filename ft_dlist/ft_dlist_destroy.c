/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:58:25 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 10:31:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

void	ft_dlist_destroy(t_dlist *dlist)
{
	t_dlist_node	*next;
	t_dlist_node	*tmp;

	next = ft_dlist_head(dlist);
	while (next != ft_dlist_end(dlist))
	{
		tmp = next;
		next = ft_dlist_extract(dlist, next);
		ft_dlist_node_delete(tmp);
	}
}
