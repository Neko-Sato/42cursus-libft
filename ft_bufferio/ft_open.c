/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:49:43 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/23 01:36:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <stdlib.h>

t_bufferio	*ft_open(int fd, int close_on_error)
{
	t_bufferio	*io;

	if (fd < 0)
		return (NULL);
	io = malloc(sizeof(t_bufferio));
	if (io)
	{
		io->_fd = fd;
		io->_capacity = BUFFERIO_DEFAULT_BUFFERSIZE;
		io->_len = 0;
		io->_pos = 0;
		io->_buf = malloc(io->_capacity);
		if (io->_buf)
			return (io);
		free(io);
	}
	if (close_on_error)
		close(fd);
	return (NULL);
}
