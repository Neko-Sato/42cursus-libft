/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:30:48 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/02 10:31:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>
#include <ft_stdlib/ft_stdlib.h>

int	ft_deque_init(t_deque *deque, size_t elemsize)
{
	size_t	chanksize;
	void	*chank;
	void	**map;

	chanksize = _DEQUE_CHANK_BYTES / elemsize;
	if (chanksize < _DEQUE_CHANK_SIZE_MIN)
		chanksize = _DEQUE_CHANK_SIZE_MIN;
	chank = malloc(chanksize * elemsize);
	if (!chank)
		return (1);
	map = malloc(_DEQUE_DEFAULT_MAP_SIZE * sizeof(void *));
	if (!map)
		return (free(chank), 1);
	deque->_map = map;
	deque->_mapsize = _DEQUE_DEFAULT_MAP_SIZE;
	deque->_chanksize = chanksize;
	deque->_elemsize = elemsize;
	deque->_start_index = deque->_mapsize / 2;
	deque->_finish_index = deque->_start_index;
	deque->_start_offset = deque->_chanksize / 2;
	deque->_finish_offset = deque->_start_offset;
	deque->_map[deque->_start_index] = chank;
	deque->_size = 0;
	return (0);
}
