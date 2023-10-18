/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:43:07 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 00:15:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>

// [sizeoftype, capacity, size, ...]
void	*ft_vector(void *array, size_t sizeoftype, size_t size, size_t capacity)
{
	void	*vector;
	size_t	vector_size;
	size_t	array_size;

	if (capacity < size)
		capacity = size;
	array_size = capacity * sizeoftype;
	if (capacity && array_size / capacity != sizeoftype)
		return (NULL);
	vector_size = sizeof(size_t[3]) + array_size;
	if (vector_size < array_size)
		return (NULL);
	vector = malloc(vector_size);
	if (!vector)
		return (NULL);
	((size_t *)vector)[0] = sizeoftype;
	((size_t *)vector)[1] = capacity;
	((size_t *)vector)[2] = size;
	if (array)
		ft_memcpy(&((size_t *)vector)[3], array, sizeoftype * size);
	return (&((size_t *)vector)[3]);
}
