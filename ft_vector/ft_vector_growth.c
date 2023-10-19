/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_growth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 18:27:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_growth(void *vector_ptr, size_t insert)
{
	void	*vector;
	size_t	size;
	size_t	capacity;

	vector = *(void **)vector_ptr;
	size = ft_vector_size(vector) + insert;
	capacity = ft_vector_capacity(vector);
	if (size <= capacity)
		return (0);
	capacity <<= 1;
	if (capacity < size)
		capacity = size;
	return (ft_vector_reserve(vector_ptr, capacity));
}
