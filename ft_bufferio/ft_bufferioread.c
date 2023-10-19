/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferioread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 19:23:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_strgen.h>
#include <unistd.h>

int	ft_bufferioread(t_bufferio *io)
{
	ssize_t	read_size;

	if (io->strgen->error)
		return (-1);
	read_size = read(io->fd, &io->strgen->buff[io->strgen->position],
			STRGEN_BUFFSIZE - io->strgen->position);
	if (read_size < 0)
		return (-1);
	io->strgen->position += read_size;
	if (io->strgen->position > STRGEN_BUFFSIZE)
		ft_strgenflush(io->strgen);
	return (!read_size);
}
