/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:22:46 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:47:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector/ft_vector.h>
#include <ft_string/ft_string.h>
#include <stdlib.h>

int	ft_vector_init(t_vector *vector, void *data, size_t size)
{
	void	*tmp;

	tmp = NULL;
	if (size)
	{
		tmp = malloc(size);
		if (!tmp)
			return (1);
	}
	if (data)
		ft_memcpy(tmp, data, size);
	vector->_data = tmp;
	vector->_size = size;
	vector->_capa = size;
	return (0);
}
