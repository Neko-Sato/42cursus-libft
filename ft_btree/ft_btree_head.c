/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:45:39 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:48:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

t_btree_node	*ft_btree_head(t_btree *btree)
{
	t_btree_node	*tmp;

	tmp = btree->_root;
	if (!tmp)
		return (NULL);
	while (tmp->_left)
		tmp = tmp->_left;
	return (tmp);
}
