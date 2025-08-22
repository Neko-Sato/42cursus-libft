/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_btree_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:26:43 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 16:02:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./__ft_btree.h"
#include <ft_btree/ft_btree.h>

void	__ft_btree_insert(t_btree *btree, t_btree_node *pos, t_btree_node *node)
{
	node->_color = FT_BTREE_RED;
	node->_parent = pos;
	node->_left = pos->_left;
	node->_right = NULL;
	pos->_left = node;
	if (node->_left)
		node->_left->_parent = node;
	btree->_size++;
	if (btree->_head->_left)
		btree->_head = btree->_head->_left;
	__ft_btree_fixup_insert(btree, node);
}
