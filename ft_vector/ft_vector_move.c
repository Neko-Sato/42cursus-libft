/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:09:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 22:12:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector/ft_vector.h>

void	ft_vector_move(t_vector *dst, t_vector *src)
{
	if (dst == src)
		return ;
	dst->_data = src->_data;
	dst->_elemsize = src->_elemsize;
	dst->_size = src->_size;
	dst->_capa = src->_capa;
}
