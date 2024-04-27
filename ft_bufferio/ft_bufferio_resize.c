/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferio_resize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 07:42:26 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 07:54:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_string.h>
#include <stdlib.h>

int	ft_bufferio_resize(t_bufferio *io, size_t capacity)
{
	void	*tmp;

	if (capacity < io->_len)
		capacity = io->_len;
	tmp = malloc(capacity);
	if (tmp)
		return (-1);
	ft_memcpy(tmp, &io->_buf[io->_pos], io->_len);
	free(io->_buf);
	io->_buf = tmp;
	io->_pos = 0;
	io->_capacity = capacity;
	return (0);
}
