/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:58:25 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 10:30:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

void	ft_slist_destroy(t_slist *slist)
{
	t_slist_node	*next;
	t_slist_node	*tmp;

	next = ft_slist_head(slist);
	while (next)
	{
		tmp = next;
		next = ft_slist_extract(slist, next);
		ft_slist_node_delete(tmp);
	}
}
