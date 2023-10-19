/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/20 02:15:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>
#include <stddef.h>

void	ft_vector_erase(void *vector, size_t index, size_t size)
{
	size_t	sizeoftype;
	void	*dst;
	void	*src;
	size_t	n;

	sizeoftype = ft_vector_sizeoftype(vector);
	dst = vector + sizeoftype * index;
	src = dst + sizeoftype * size;
	n = sizeoftype * (ft_vector_size(vector) - index - size);
	ft_memcpy(dst, src, n);
	((size_t *)vector)[-1] -= size;
}
