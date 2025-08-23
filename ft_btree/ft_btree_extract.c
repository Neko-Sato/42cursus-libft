/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_extract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 22:52:52 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:30:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

static void	_extract(t_btree *btree, t_btree_node *node)
{
	t_btree_node	*child;

	if (node->_left)
		child = node->_left;
	else
		child = node->_right;
	if (child)
		child->_parent = node->_parent;
	if (node->_parent->_left == node)
		node->_parent->_left = child;
	else
		node->_parent->_right = child;
	node->_parent = NULL;
	node->_left = NULL;
	node->_right = NULL;
	node->_color = _BTREE_RED;
	if (child)
		ft__btree_fixup(btree, child);
}

t_btree_node	*ft_btree_extract(t_btree *btree, t_btree_node *node)
{
	t_btree_node	*tmp;

	tmp = ft_btree_node_next(node);
	if (node->_left && node->_right)
	{
		_extract(btree, tmp);
		ft__btree_replace(node, tmp);
	}
	else
		_extract(btree, node);
	btree->_size--;
	if (node == btree->_head)
		btree->_head = tmp;
	return (tmp);
}
