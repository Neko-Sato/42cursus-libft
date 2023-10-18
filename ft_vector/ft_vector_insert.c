/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 01:38:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>

int	ft_vector_insert(void *vector_ptr, size_t index, void *value)
{
	size_t	sizeoftype;
	void	*vector;
	void	*dst;
	void	*src;

	if (ft_vector_growth(vector_ptr))
		return (-1);
	vector = *(void **)vector_ptr;
	sizeoftype = ft_vector_sizeoftype(vector);
	src = vector + (sizeoftype * index);
	dst = src + sizeoftype;
	((size_t *)vector)[-1]++;
	ft_memmove(dst, src, sizeoftype * (ft_vector_size(vector) - index));
	ft_memcpy(src, value, sizeoftype);
	return (0);
}
