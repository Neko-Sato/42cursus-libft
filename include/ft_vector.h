/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:37:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 01:10:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

void	*ft_vector(void *array, size_t sizeoftype, size_t size,
			size_t capacity);
void	ft_vector_del(void *vector);
size_t	ft_vector_size(void *vector);
size_t	ft_vector_capacity(void *vector);
size_t	ft_vector_sizeoftype(void *vector);
int		ft_vector_reserve(void *vector_ptr, size_t capacity);
int		ft_vector_shrink_to_fit(void *vector_ptr);

void	ft_vector_clear(void *vector);
void	ft_vector_erase(void *vector, size_t index);

#endif