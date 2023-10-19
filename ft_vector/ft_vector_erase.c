/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 19:21:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_vector.h>
#include <stddef.h>

void	ft_vector_erase(void *vector, size_t index, size_t size)
{
	void	*dst;
	void	*src;

	dst = vector + index;
	src = dst + size;
	ft_memcpy(dst, src, ft_vector_size(vector) - index - size);
	((size_t *)vector)[-1] -= size;
}
