/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferio_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 07:42:26 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 08:41:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_string.h>
#include <stdlib.h>

int	ft_bufferio_read(t_bufferio *io, size_t size)
{
	ssize_t	len;

	if (io->_len < size)
	{
		if (io->_capacity < size)
		{
			if (ft_bufferio_resize(io, size))
				return (-1);
		}
		else if (io->_capacity < io->_pos + size)
		{
			ft_memcpy(io->_buf, &io->_buf[io->_pos], io->_len);
			io->_pos = 0;
		}
		len = read(io->_fd, &io->_buf[io->_pos + io->_len], io->_capacity
				- (io->_pos + io->_len));
		if (len == -1)
			return (-1);
		io->_len += len;
	}
	return (0);
}
