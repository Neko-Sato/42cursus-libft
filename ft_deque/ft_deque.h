/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 01:51:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 18:46:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stddef.h>

# define FT_DEQUE_CHANK_BYTES 512
# define FT_DEQUE_CHANK_SIZE_MIN 8
# define FT_DEQUE_DEFAULT_MAP_SIZE 8
# define FT_DEQUE_MAP_GROWTH_FACTOR 2

typedef struct s_deque
{
	void	**_map;
	size_t	_mapsize;
	size_t	_chanksize;
	size_t	_elemsize;
	size_t	_start_index;
	size_t	_start_offset;
	size_t	_finish_index;
	size_t	_finish_offset;
	size_t	_size;
}			t_deque;

int			ft_deque_init(t_deque *deque, size_t elemsize);
void		ft_deque_destroy(t_deque *deque);

size_t		ft_deque_size(t_deque *deque);
void		*ft_deque_at(t_deque *deque, size_t n);
int			ft_deque_expand_front(t_deque *deque, size_t size);
int			ft_deque_expand_back(t_deque *deque, size_t size);
void		ft_deque_shrink_front(t_deque *deque, size_t size);
void		ft_deque_shrink_back(t_deque *deque, size_t size);

#endif
