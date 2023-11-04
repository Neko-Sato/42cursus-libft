/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:38:34 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/20 02:23:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stddef.h>

int	ft_vector_push_back(void *vector_ptr, void *value)
{
	return (ft_vector_insert(vector_ptr, ft_vector_size(*(void **)vector_ptr),
			value, 1));
}