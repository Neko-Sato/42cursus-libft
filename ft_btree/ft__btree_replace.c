/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__btree_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:56:01 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:29:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

void	ft__btree_replace(t_btree_node *pos, t_btree_node *node)
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
	pos->_color = _BTREE_RED;
}
