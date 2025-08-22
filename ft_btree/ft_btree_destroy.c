/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:33:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 10:35:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

void	ft_btree_destroy(t_btree *btree)
{
	t_btree_node	*next;
	t_btree_node	*tmp;

	next = ft_btree_head(btree);
	while (next)
	{
		tmp = next;
		next = ft_btree_extract(btree, next);
		ft_btree_node_delete(tmp);
	}
	btree->_compar = NULL;
}
