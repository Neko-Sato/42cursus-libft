/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:08:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 08:51:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_string.h>
#include <unistd.h>

ssize_t	ft_read(t_bufferio *io, char *buf, size_t size)
{
	if (ft_bufferio_read(io, size))
		return (-1);
	if (io->_len < size)
		size = io->_len;
	ft_memcpy(buf, &io->_buf[io->_pos], size);
	io->_pos += size;
	io->_len -= size;
	return (size);
}
