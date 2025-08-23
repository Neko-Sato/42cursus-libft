/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_expand_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:44:23 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:34:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>
#include <ft_string/ft_string.h>
#include <stdlib.h>

static inline int	_reserve_map_back_internal(t_deque *deque, size_t n,
		void ***map, size_t *mapsize)
{
	void	**new_map;
	size_t	new_mapsize;

	if (n < deque->_mapsize)
	{
		new_map = deque->_map;
		new_mapsize = deque->_mapsize;
	}
	else
	{
		new_mapsize = deque->_mapsize * FT_DEQUE_MAP_GROWTH_FACTOR;
		if (new_mapsize < n)
			new_mapsize = n;
		new_map = malloc(new_mapsize * sizeof(void *));
		if (!new_map)
			return (1);
	}
	*map = new_map;
	*mapsize = new_mapsize;
	return (0);
}

static inline int	_reserve_map_back(t_deque *deque, size_t n)
{
	size_t	chank_cnt;
	void	**new_map;
	size_t	new_mapsize;
	size_t	new_start_index;

	chank_cnt = deque->_finish_index - deque->_start_index + 1;
	if (_reserve_map_back_internal(deque, chank_cnt + n, &new_map,
			&new_mapsize))
		return (1);
	new_start_index = (new_mapsize - n + chank_cnt) / 2;
	ft_memmove(&new_map[new_start_index], &deque->_map[deque->_start_index],
		chank_cnt * sizeof(void *));
	if (deque->_map != new_map)
		free(deque->_map);
	deque->_map = new_map;
	deque->_mapsize = new_mapsize;
	deque->_start_index = new_start_index;
	deque->_finish_index = new_start_index + chank_cnt - 1;
	return (0);
}

static inline int	_reserve_chank_back(t_deque *deque, size_t n)
{
	size_t	i;

	if (deque->_mapsize - deque->_finish_index < n && _reserve_map_back(deque,
			n))
		return (1);
	i = n;
	while (0 < i)
	{
		deque->_map[deque->_finish_index + i] = malloc(deque->_chanksize
				* sizeof(void *));
		if (!deque->_map[deque->_finish_index + i])
		{
			while (i < n)
				free(deque->_map[deque->_finish_index + ++i]);
			return (1);
		}
		i--;
	}
	return (0);
}

int	ft_deque_expand_back(t_deque *deque, size_t size)
{
	size_t	slack;
	size_t	required_size;
	size_t	required_chanks;

	slack = deque->_chanksize - deque->_finish_offset;
	if (slack < size)
	{
		required_size = size - slack;
		required_chanks = (required_size + deque->_chanksize - 1)
			/ deque->_chanksize;
		if (_reserve_chank_back(deque, required_chanks))
			return (1);
		deque->_finish_index += required_chanks;
		deque->_finish_offset = (required_size - 1) % deque->_chanksize + 1;
	}
	else
		deque->_finish_offset += size;
	deque->_size += size;
	return (0);
}
