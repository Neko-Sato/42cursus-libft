/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 18:48:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_insert(void *vector_ptr, size_t index, void *value, size_t size)
{
	void	*vector;
	void	*dst;
	void	*src;

	if (ft_vector_growth(vector_ptr, size))
		return (-1);
	vector = *(void **)vector_ptr;
	src = vector + index;
	dst = src + size;
	((size_t *)vector)[-1] += size;
	ft_memmove(dst, src, ft_vector_size(vector) - index - size);
	ft_memcpy(src, value, size);
	return (0);
}
