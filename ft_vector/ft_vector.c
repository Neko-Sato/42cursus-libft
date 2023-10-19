/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:03:08 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/20 02:28:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

void	*ft_vector(size_t sizeoftype, void *array, size_t size)
{
	return (ft_vector_new(sizeoftype, array, size, size));
}
