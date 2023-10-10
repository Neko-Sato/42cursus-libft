/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:46:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_strgen.h>
#include <ft_string.h>
#include <unistd.h>

ssize_t	ft_write(t_bufferio *io, char *str)
{
	return (write(io->fd, str, ft_strlen(str)));
}
