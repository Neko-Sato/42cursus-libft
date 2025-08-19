/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:22:46 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/15 15:08:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector/ft_vector.h>

int	ft_vector_init(t_vector *vector, size_t elemsize)
{
	vector->_data = NULL;
	vector->_elemsize = elemsize;
	vector->_size = 0;
	vector->_capa = 0;
	return (0);
}
