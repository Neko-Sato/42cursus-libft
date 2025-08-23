/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__btree_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:26:43 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:29:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

void	ft__btree_insert(t_btree *btree, t_btree_node *pos, t_btree_node *node)
{
	node->_color = _BTREE_RED;
	node->_parent = pos;
	node->_left = pos->_left;
	node->_right = NULL;
	pos->_left = node;
	if (node->_left)
		node->_left->_parent = node;
	ft__btree_fixup(btree, node);
	btree->_size++;
	if (node->_parent == btree->_head)
		btree->_head = node;
}
