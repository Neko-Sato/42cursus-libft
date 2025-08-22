/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_replace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:37:07 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 15:58:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./__ft_btree.h"
#include <ft_btree/ft_btree.h>

static inline void	__node_replace(t_btree_node *pos, t_btree_node *node)
{
	node->_parent = pos->_parent;
	node->_left = pos->_left;
	node->_right = pos->_right;
	node->_color = pos->_color;
	if (pos->_parent->_left == pos)
		pos->_parent->_left = node;
	else
		pos->_parent->_right = node;
	if (pos->_left)
		pos->_left->_parent = node;
	if (pos->_right)
		pos->_right->_parent = node;
	pos->_parent = NULL;
	pos->_left = NULL;
	pos->_right = NULL;
	pos->_color = FT_BTREE_RED;
}

t_btree_node	*ft_btree_insert_replace(t_btree *btree, t_btree_node *node)
{
	t_btree_node	*pos;

	pos = ft_btree_lower_bound(btree, node->data);
	if (pos != ft_btree_end(btree) && !btree->_compar(node->data, pos->data))
	{
		__node_replace(pos, node);
		return (pos);
	}
	else
	{
		__ft_btree_insert(btree, pos, node);
		return (NULL);
	}
}
