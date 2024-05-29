/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:28:11 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/30 05:03:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <unistd.h>

int	ft_fflush(t_file *stream)
{
	size_t	request;
	ssize_t	size;

	request = stream->w_ptr - stream->w_base;
	if (!request)
		return (0);
	size = write(stream->fileno, stream->w_base, request);
	if (size < 0)
	{
		stream->flags |= _FT_IO_ERR_SEEN;
		return (FT_EOF);
	}
	stream->w_ptr = stream->w_base;
	return (0);
}
