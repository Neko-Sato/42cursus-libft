/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:39:33 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/11 20:40:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <ft_vector/ft_vector.h>

int	ft_vector_push_back(t_vector *vector, void *elem)
{
	size_t	pos;

	pos = vector->_size;
	if (ft_vector_resize(vector, pos + 1))
		return (1);
	ft_memcpy(&vector->_data[pos * vector->_elemsize], elem, vector->_elemsize);
	return (0);
}
