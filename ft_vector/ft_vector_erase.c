/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 01:36:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>

void	ft_vector_erase(void *vector, size_t index)
{
	size_t	sizeoftype;
	void	*dst;
	void	*src;

	sizeoftype = ft_vector_sizeoftype(vector);
	dst = vector + (sizeoftype * index);
	src = dst + sizeoftype;
	ft_memcpy(dst, src, sizeoftype * (ft_vector_size(vector) - index));
	((size_t *)vector)[-1]--;
}
