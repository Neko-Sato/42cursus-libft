/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_shrink_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 03:49:01 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 19:40:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>
#include <stdlib.h>

static inline void	__erase_chank_back(t_deque *deque, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(deque->_map[deque->_finish_index - i++]);
}

void	ft_deque_shrink_back(t_deque *deque, size_t size)
{
	size_t	remove_size;
	size_t	remove_chanks;

	if (deque->_finish_offset < size)
	{
		remove_size = size + deque->_chanksize - deque->_finish_offset;
		remove_chanks = (remove_size - 1) / deque->_chanksize;
		__erase_chank_back(deque, remove_chanks);
		deque->_finish_index -= remove_chanks;
		deque->_finish_offset = remove_size % deque->_chanksize;
	}
	else
		deque->_finish_offset -= size;
	deque->_size -= size;
}
