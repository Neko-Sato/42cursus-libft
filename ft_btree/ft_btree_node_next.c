/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:26:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 14:31:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_node_next(t_btree_node *node)
{
	t_btree_node	*next;

	if (node->_right)
	{
		next = node->_right;
		while (next->_left)
			next = next->_left;
	}
	else
	{
		next = node->_parent;
		while (next->_left != node)
		{
			node = next;
			next = next->_parent;
		}
	}
	return (next);
}
