/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:33:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 16:13:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

void	ft_btree_destroy(t_btree *btree)
{
	t_btree_node	*tmp;

	tmp = ft_btree_head(btree);
	while (tmp)
		tmp = ft_btree_erase(btree, tmp);
	btree->_compar = NULL;
}
