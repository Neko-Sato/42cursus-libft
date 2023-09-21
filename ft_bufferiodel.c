/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferiodel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:14:53 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/21 23:32:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_bufferiodel(t_bufferio *io, int do_close)
{
	ft_strgendel(io->strgen);
	if (do_close)
		close(io->fd);
	free(io);
}
