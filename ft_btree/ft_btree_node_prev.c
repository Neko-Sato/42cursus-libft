/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:35:05 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 16:35:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree.h>

t_btree_node	*ft_btree_node_prev(t_btree_node *node)
{
	t_btree_node	*prev;

	prev = NULL;
	if (node->_left)
	{
		prev = node->_left;
		while (prev->_right)
			prev = prev->_right;
	}
	else
	{
		prev = node->_parent;
		while (prev && prev->_left == node)
		{
			node = prev;
			prev = prev->_parent;
		}
	}
	return (prev);
}
