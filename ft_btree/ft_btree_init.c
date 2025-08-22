/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:32:43 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 09:25:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

int	ft_btree_init(t_btree *btree, int (*compar)(const void *, const void *))
{
	btree->_root = NULL;
	btree->_head = NULL;
	btree->_tail = NULL;
	btree->_size = 0;
	btree->_compar = compar;
	return (0);
}
