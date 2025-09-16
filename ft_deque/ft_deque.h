/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 01:51:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/17 02:44:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stddef.h>

# define _DEQUE_CHANK_BYTES 512
# define _DEQUE_DEFAULT_MAP_SIZE 8
# define _DEQUE_MAP_GROWTH_FACTOR 2

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
void		ft_deque_move(t_deque *dst, t_deque *src);

size_t		ft_deque_size(const t_deque *deque);
void		*ft_deque_at(const t_deque *deque, size_t n);
int			ft_deque_expand_front(t_deque *deque, size_t size);
int			ft_deque_expand_back(t_deque *deque, size_t size);
void		ft_deque_shrink_front(t_deque *deque, size_t size);
void		ft_deque_shrink_back(t_deque *deque, size_t size);

#endif
