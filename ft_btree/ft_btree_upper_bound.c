/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_upper_bound.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:40:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:20:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_upper_bound(const t_btree *btree, const void *data)
{
	t_btree_node	*node;
	t_btree_node	*upper_bound;

	node = btree->_root;
	upper_bound = ft_btree_end(btree);
	while (node)
	{
		if (btree->_less(data, node->data))
		{
			upper_bound = node;
			node = node->_left;
		}
		else
			node = node->_right;
	}
	return (upper_bound);
}
