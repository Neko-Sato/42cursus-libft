/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferiodel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:14:53 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/30 12:40:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_strgen.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bufferiodel(t_bufferio *io, int do_close)
{
	if (!io)
		return ;
	ft_strgendel(io->strgen);
	if (do_close)
		close(io->fd);
	free(io);
}
