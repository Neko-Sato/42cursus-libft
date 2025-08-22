/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_unique.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:37:07 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 16:02:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./__ft_btree.h"
#include <ft_btree/ft_btree.h>

int	ft_btree_insert_unique(t_btree *btree, t_btree_node *node)
{
	t_btree_node	*pos;

	pos = ft_btree_lower_bound(btree, node->data);
	if (pos != ft_btree_end(btree) && !btree->_compar(node->data, pos->data))
		return (1);
	else
		__ft_btree_insert(btree, pos, node);
	return (0);
}
