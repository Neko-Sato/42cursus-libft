/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_replace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:37:07 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:24:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_insert_replace(t_btree *btree, t_btree_node *node)
{
	t_btree_node	*pos;

	pos = ft_btree_lower_bound(btree, node->data);
	if (pos != ft_btree_end(btree) && !btree->_less(node->data, pos->data)
		&& !btree->_less(pos->data, node->data))
	{
		ft__btree_replace(pos, node);
		return (pos);
	}
	else
	{
		ft__btree_insert(btree, pos, node);
		return (NULL);
	}
}
