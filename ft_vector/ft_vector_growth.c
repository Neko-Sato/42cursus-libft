/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_growth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 01:42:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_growth(void *vector_ptr)
{
	void	*vector;
	size_t	capacity;

	vector = *(void **)vector_ptr;
	capacity = ft_vector_capacity(vector);
	if (capacity <= ft_vector_size(vector))
	{
		if (capacity)
			capacity <<= 1;
		else
			capacity = 1;
		return (ft_vector_reserve(vector_ptr, capacity));
	}
	return (0);
}
