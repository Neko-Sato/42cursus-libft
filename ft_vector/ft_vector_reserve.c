/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:39:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 00:21:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stdlib.h>

int	ft_vector_reserve(void *vector_ptr, size_t capacity)
{
	void	*old_vector;
	void	*new_vector;

	old_vector = *(void **)vector_ptr;
	new_vector = ft_vector(
			old_vector,
			ft_vector_sizeoftype(old_vector),
			ft_vector_size(old_vector),
			capacity);
	if (!new_vector)
		return (-1);
	ft_vector_del(old_vector);
	*(void **)vector_ptr = new_vector;
	return (0);
}
