/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:49:08 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/17 02:46:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_find(const t_btree *btree, const void *data)
{
	t_btree_node	*current;
	int				cmp;

	current = btree->_root;
	while (current)
	{
		cmp = btree->_compar(data, current->data);
		if (cmp == 0)
			return (current);
		else if (cmp < 0)
			current = current->_left;
		else
			current = current->_right;
	}
	return (NULL);
}
