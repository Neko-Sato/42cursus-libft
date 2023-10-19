/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_pop_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:36:07 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 18:50:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stddef.h>

void	ft_vector_pop_back(void *vector, size_t size)
{
	return (ft_vector_erase(vector, ft_vector_size(vector) - size, size));
}
