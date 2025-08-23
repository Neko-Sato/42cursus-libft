/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:11:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 22:12:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>

void	ft_deque_move(t_deque *dst, t_deque *src)
{
	if (dst == src)
		return ;
	dst->_map = src->_map;
	dst->_mapsize = src->_mapsize;
	dst->_chanksize = src->_chanksize;
	dst->_elemsize = src->_elemsize;
	dst->_start_index = src->_start_index;
	dst->_start_offset = src->_start_offset;
	dst->_finish_index = src->_finish_index;
	dst->_finish_offset = src->_finish_offset;
	dst->_size = src->_size;
}
