/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:32:10 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 16:19:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>
#include <stdlib.h>

void	ft_deque_destroy(t_deque *deque)
{
	size_t	i;

	i = deque->_finish_index - deque->_start_index + 1;
	while (0 < i)
		free(deque->_map[deque->_start_index + --i]);
	free(deque->_map);
	deque->_map = NULL;
	deque->_mapsize = 0;
	deque->_chanksize = 0;
	deque->_elemsize = 0;
	deque->_start_index = 0;
	deque->_start_offset = 0;
	deque->_finish_index = 0;
	deque->_finish_offset = 0;
	deque->_size = 0;
}
