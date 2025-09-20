/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:22:46 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/20 22:13:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <ft_vector/ft_vector.h>
#include <stdlib.h>

static inline void	_move(t_vector *vector, char *tmp)
{
	size_t	i;

	i = 0;
	while (i < vector->_size)
	{
		vector->_move(tmp + i * vector->_elemsize, vector->_data + i
			* vector->_elemsize);
		i++;
	}
}

static inline int	_reserve(t_vector *vector, size_t n)
{
	void	*tmp;
	size_t	capa;

	if (vector->_capa < n)
	{
		capa = vector->_capa * _VECTOR_GROWTH_FACTOR;
		if (capa < n)
			capa = n;
		tmp = malloc(capa * vector->_elemsize);
		if (!tmp)
			return (1);
		if (vector->_move)
			_move(vector, tmp);
		else
			ft_memcpy(tmp, vector->_data, vector->_size * vector->_elemsize);
		free(vector->_data);
		vector->_data = tmp;
		vector->_capa = capa;
	}
	return (0);
}

int	ft_vector_resize(t_vector *vector, size_t n)
{
	if (_reserve(vector, n))
		return (-1);
	vector->_size = n;
	return (0);
}
