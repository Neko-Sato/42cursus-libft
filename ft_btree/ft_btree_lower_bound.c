/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_lower_bound.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:36:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 18:48:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_lower_bound(t_btree *btree, const void *data)
{
	t_btree_node	*node;
	t_btree_node	*lower_bound;

	node = btree->_root;
	lower_bound = NULL;
	while (node)
	{
		if (btree->_compar(data, node->data) <= 0)
		{
			lower_bound = node;
			node = node->_left;
		}
		else
			node = node->_right;
	}
	return (lower_bound);
}
