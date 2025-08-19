/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 02:35:29 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/19 16:20:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_deque/ft_deque.h>

void	*ft_deque_at(t_deque *deque, size_t n)
{
	size_t	index;
	size_t	offset;

	n += deque->_start_index;
	index = deque->_start_index + n / deque->_chanksize;
	offset = n % deque->_chanksize;
	return ((char *)deque->_map[index] + deque->_elemsize * offset);
}
