/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:43:14 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:42:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <ft_vector/ft_vector.h>
#include <stdlib.h>

int	ft_vector_reserve(t_vector *vector, size_t new_capa)
{
	void	*tmp;
	size_t	capa;

	if (vector->_capa < new_capa)
	{
		capa = vector->_capa * FT_VECTOR_GROWTH_FACTOR;
		if (capa < new_capa)
			capa = new_capa;
		tmp = malloc(capa);
		if (!tmp)
			return (1);
		ft_memcpy(tmp, vector->_data, vector->_size);
		free(vector->_data);
		vector->_data = tmp;
		vector->_capa = capa;
	}
	return (0);
}
