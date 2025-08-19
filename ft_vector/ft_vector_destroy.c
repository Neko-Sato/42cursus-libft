/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:22:46 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/12 02:11:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector/ft_vector.h>
#include <stdlib.h>

void	ft_vector_destroy(t_vector *vector)
{
	if (vector->_data)
	{
		free(vector->_data);
		vector->_data = NULL;
	}
	vector->_elemsize = 0;
	vector->_size = 0;
	vector->_capa = 0;
}
