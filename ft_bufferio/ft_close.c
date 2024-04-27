/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:49:43 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 08:41:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_close(t_bufferio *io, int do_close)
{
	if (do_close)
		close(io->_fd);
	free(io->_buf);
	free(io);
}
