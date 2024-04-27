/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:08:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 08:15:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <unistd.h>

ssize_t	ft_write(t_bufferio *io, char *buf, size_t size)
{
	return (write(io->_fd, buf, size));
}
