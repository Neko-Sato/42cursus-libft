/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_pop_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:36:07 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/20 02:22:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

void	ft_vector_pop_back(void *vector)
{
	return (ft_vector_erase(vector, ft_vector_size(vector) - 1, 1));
}
