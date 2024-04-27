/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:49:43 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 08:41:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <stdlib.h>

t_bufferio	*ft_open(int fd, int close_on_error)
{
	t_bufferio	*io;

	io = malloc(sizeof(t_bufferio));
	if (!io)
	{
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	io->_fd = fd;
	io->_buf = malloc(BUFFERIO_DEFAULT_BUFFERSIZE);
	if (!io->_buf)
	{
		free(io);
		return (NULL);
	}
	io->_capacity = BUFFERIO_DEFAULT_BUFFERSIZE;
	io->_len = 0;
	io->_pos = 0;
	return (io);
}
