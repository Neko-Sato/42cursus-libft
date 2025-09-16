/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:26:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/17 02:46:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_node_prev(const t_btree_node *node)
{
	t_btree_node	*prev;

	if (node->_left)
	{
		prev = node->_left;
		while (prev->_right)
			prev = prev->_right;
	}
	else
	{
		prev = node->_parent;
		while (prev->_right != node)
		{
			node = prev;
			prev = prev->_parent;
		}
	}
	return (prev);
}
