/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_node_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:23:03 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 18:48:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>
#include <stdlib.h>

t_btree_node	*ft_btree_node_new(size_t size)
{
	t_btree_node	*node;

	node = malloc(sizeof(t_btree_node) + size);
	if (!node)
		return (NULL);
	node->_parent = NULL;
	node->_left = NULL;
	node->_right = NULL;
	node->_color = FT_BTREE_COLOR_RED;
	return (node);
}
