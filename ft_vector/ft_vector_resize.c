/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:03:08 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 18:07:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_resize(void *vector_ptr, size_t size)
{
	void	*vector;

	vector = *(void **)vector_ptr;
	if (ft_vector_capacity(vector) < size)
		return (ft_vector_reserve(vector_ptr, size));
	((size_t *)vector)[-1] = size;
	return (0);
}
