/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_upper_bound.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:40:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 16:41:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_upper_bound(t_btree *btree, const void *data)
{
	t_btree_node	*node;
	t_btree_node	*upper_bound;

	node = btree->_root;
	upper_bound = NULL;
	while (node)
	{
		if (btree->_compar(data, node->data) < 0)
		{
			upper_bound = node;
			node = node->_left;
		}
		else
			node = node->_right;
	}
	return (upper_bound);
}
