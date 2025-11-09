/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:49:08 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:26:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_find(const t_btree *btree, const void *data)
{
	t_btree_node	*current;

	current = btree->_root;
	while (current)
	{
		if (btree->_less(data, current->data))
			current = current->_left;
		else if (btree->_less(current->data, data))
			current = current->_right;
		else
			return (current);
	}
	return (NULL);
}
