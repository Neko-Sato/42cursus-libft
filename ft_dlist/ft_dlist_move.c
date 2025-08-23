/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:16:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 22:31:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

void	ft_dlist_move(t_dlist *dst, t_dlist *src)
{
	if (dst == src)
		return ;
	if (src->_size)
	{
		dst->_head = src->_head;
		dst->_tail = src->_tail;
		dst->_head->_prev = (void *)dst;
		dst->_head->_next = (void *)dst;
	}
	else
	{
		dst->_head = (void *)dst;
		dst->_tail = (void *)dst;
	}
	dst->_size = src->_size;
}
