/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_multi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:37:07 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:27:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

void	ft_btree_insert_multi(t_btree *btree, t_btree_node *node)
{
	ft__btree_insert(btree, ft_btree_upper_bound(btree, node->data), node);
}
