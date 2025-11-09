/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:18:06 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:20:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_btree/ft_btree.h>

void	ft_btree_move(t_btree *dst, t_btree *src)
{
	if (dst == src)
		return ;
	if (src->_root)
		src->_root->_parent = (void *)dst;
	dst->_root = src->_root;
	dst->_head = src->_head;
	dst->_less = src->_less;
	dst->_size = src->_size;
}
