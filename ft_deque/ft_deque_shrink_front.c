/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_shrink_front.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 03:49:01 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:35:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>
#include <stdlib.h>

static inline void	_erase_chank_front(t_deque *deque, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(deque->_map[deque->_start_index + i++]);
}

void	ft_deque_shrink_front(t_deque *deque, size_t size)
{
	size_t	remove_size;
	size_t	remove_chanks;

	if (deque->_chanksize - deque->_start_offset < size)
	{
		remove_size = size + deque->_start_offset;
		remove_chanks = (remove_size - 1) / deque->_chanksize;
		_erase_chank_front(deque, remove_chanks);
		deque->_start_index += remove_chanks;
		deque->_start_offset = (remove_size - 1) % deque->_chanksize + 1;
	}
	else
		deque->_start_offset += size;
	deque->_size -= size;
}
