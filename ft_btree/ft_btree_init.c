/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:32:43 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:24:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

int	ft_btree_init(t_btree *btree, int (*less)(const void *, const void *))
{
	btree->_root = NULL;
	btree->_head = ft_btree_end(btree);
	btree->_size = 0;
	btree->_less = less;
	return (0);
}
