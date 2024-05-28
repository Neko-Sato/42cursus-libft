/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 02:04:53 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 03:23:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <malloc.h>
#include <unistd.h>

static inline size_t	ft_io_read_internal(void *buf, size_t len,
							t_file *stream);

size_t	ft_io_read(void *buf, size_t len, t_file *stream)
{
	if (stream->flags & _FT_IO_NO_READS)
		return (0);
	if (!stream->r_base)
	{
		stream->r_base = malloc(_FT_IO_BUFSIZ);
		if (!stream->r_base)
		{
			stream->flags |= _FT_IO_ERR_SEEN;
			return (0);
		}
		stream->r_end = stream->r_base;
		stream->r_ptr = stream->r_base;
	}
	return (ft_io_read_internal(buf, len, stream));
}

static inline size_t	ft_io_read_internal(void *buf, size_t len,
		t_file *stream)
{
	ssize_t	size;
	char	*p;

	p = buf;
	while (len--)
	{
		if (stream->r_ptr >= stream->r_end)
		{
			size = read(stream->fileno, stream->r_base, BUFSIZ);
			if (size < 0)
			{
				stream->flags |= _FT_IO_ERR_SEEN;
				break ;
			}
			else if (size == 0)
			{
				stream->flags |= _FT_IO_EOF_SEEN;
				break ;
			}
			stream->r_ptr = stream->r_base;
			stream->r_end = stream->r_base + size;
		}
		*p++ = *stream->r_ptr++;
	}
	return (p - (char *)buf);
}
