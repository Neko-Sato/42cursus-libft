/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/20 02:13:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_reserve(void *vector_ptr, size_t capacity)
{
	void	*old_vector;
	void	*new_vector;

	if (ft_vector_capacity(*(void **)vector_ptr) == capacity)
		return (0);
	old_vector = *(void **)vector_ptr;
	new_vector = ft_vector_new(
			ft_vector_sizeoftype(old_vector),
			old_vector,
			ft_vector_size(old_vector),
			capacity);
	if (!new_vector)
		return (-1);
	ft_vector_del(old_vector);
	*(void **)vector_ptr = new_vector;
	return (0);
}
