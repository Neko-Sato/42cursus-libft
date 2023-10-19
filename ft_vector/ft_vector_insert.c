/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/20 02:36:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_insert(void *vector_ptr, size_t index, void *value, size_t size)
{
	void	*vector;
	size_t	sizeoftype;
	void	*dst;
	void	*src;
	size_t	n;

	if (ft_vector_growth(vector_ptr, size))
		return (-1);
	vector = *(void **)vector_ptr;
	sizeoftype = ft_vector_sizeoftype(vector);
	src = vector + sizeoftype * index;
	dst = src + sizeoftype * size;
	n = sizeoftype * (ft_vector_size(vector) - index);
	((size_t *)vector)[-1] += size;
	ft_memmove(dst, src, n);
	ft_memcpy(src, value, sizeoftype * size);
	return (0);
}
