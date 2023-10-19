/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:37:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 18:50:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

void	*ft_vector(void *array, size_t size, size_t capacity);
void	ft_vector_del(void *vector);

size_t	ft_vector_size(void *vector);
size_t	ft_vector_capacity(void *vector);

int		ft_vector_reserve(void *vector_ptr, size_t capacity);
int		ft_vector_resize(void *vector_ptr, size_t size);
int		ft_vector_shrink_to_fit(void *vector_ptr);
int		ft_vector_growth(void *vector_ptr, size_t insert);

void	ft_vector_clear(void *vector);
void	ft_vector_erase(void *vector, size_t index, size_t size);
int		ft_vector_insert(void *vector_ptr, size_t index, void *value,
			size_t size);

void	ft_vector_pop_back(void *vector, size_t size);
int		ft_vector_push_back(void *vector_ptr, void *value, size_t size);

#endif