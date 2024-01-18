/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:43:07 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 18:49:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>
#include <stdlib.h>

void	*ft_vector_new(size_t sizeoftype, void *array, size_t size,
		size_t capacity)
{
	t_vector	*vector;

	if (capacity < size)
		capacity = size;
	vector = malloc(sizeof(t_vector) + sizeoftype * capacity);
	if (!vector)
		return (NULL);
	vector->sizeoftype = sizeoftype;
	vector->capacity = capacity;
	vector->size = size;
	if (array)
		ft_memcpy(vector->data, array, sizeoftype * size);
	return (vector->data);
}
