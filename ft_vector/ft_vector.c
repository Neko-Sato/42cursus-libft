/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:43:07 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 18:19:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>

// [capacity, size, ...]
void	*ft_vector(void *array, size_t size, size_t capacity)
{
	void	*vector;

	if (capacity < size)
		capacity = size;
	vector = malloc(sizeof(size_t[3]) + capacity);
	if (!vector)
		return (NULL);
	vector = &((size_t *)vector)[2];
	((size_t *)vector)[-2] = capacity;
	((size_t *)vector)[-1] = size;
	if (array)
		ft_memcpy(vector, array, size);
	return (vector);
}
