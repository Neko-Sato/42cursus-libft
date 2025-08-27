/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__btree_fixup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:05:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/26 19:09:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

static void	_rotate_left(t_btree_node *x)
{
	t_btree_node	*y;

	y = x->_right;
	x->_right = y->_left;
	if (y->_left)
		y->_left->_parent = x;
	y->_parent = x->_parent;
	if (x->_parent->_left == x)
		x->_parent->_left = y;
	else
		x->_parent->_right = y;
	y->_left = x;
	x->_parent = y;
}

static void	_rotate_right(t_btree_node *y)
{
	t_btree_node	*x;

	x = y->_left;
	y->_left = x->_right;
	if (x->_right)
		x->_right->_parent = y;
	x->_parent = y->_parent;
	if (y->_parent->_left == y)
		y->_parent->_left = x;
	else
		y->_parent->_right = x;
	x->_right = y;
	y->_parent = x;
}

static inline void	_black_uncle(t_btree_node **node, t_btree_node **parent,
		t_btree_node **grandparent)
{
	static void (*const	rotate[])(t_btree_node *) = {
		_rotate_left, _rotate_right
	};
	int					zig;
	int					zag;

	zig = (*grandparent)->_left == *parent;
	zag = (*parent)->_left == *node;
	if (zig != zag)
	{
		rotate[zag](*parent);
		*node = *parent;
		(*parent) = (*node)->_parent;
	}
	rotate[zig](*grandparent);
	(*parent)->_color = _BTREE_BLACK;
	(*grandparent)->_color = _BTREE_RED;
}

void	ft__btree_fixup(t_btree *btree, t_btree_node *node)
{
	t_btree_node	*parent;
	t_btree_node	*grandparent;
	t_btree_node	*uncle;

	parent = node->_parent;
	while (parent != ft_btree_end(btree) && parent->_color == _BTREE_RED)
	{
		grandparent = parent->_parent;
		if (grandparent->_left == parent)
			uncle = grandparent->_right;
		else
			uncle = grandparent->_left;
		if (!uncle || uncle->_color == _BTREE_BLACK)
		{
			_black_uncle(&node, &parent, &grandparent);
			break ;
		}
		parent->_color = _BTREE_BLACK;
		uncle->_color = _BTREE_BLACK;
		grandparent->_color = _BTREE_RED;
		node = grandparent;
		parent = node->_parent;
	}
	btree->_root->_color = _BTREE_BLACK;
}
