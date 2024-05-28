/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:56:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 05:47:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <malloc.h>
#include <unistd.h>

static inline size_t	ft_io_write_internal(const void *buf, size_t len,
							t_file *stream);
static inline size_t	unbuffered_write(const void *buf, size_t len,
							t_file *stream);
static inline size_t	buffered_write(const void *buf, size_t len,
							t_file *stream);

size_t	ft_io_write(const void *buf, size_t len, t_file *stream)
{
	if (stream->flags & _FT_IO_NO_WRITES)
		return (0);
	if (stream->flags & _FT_IO_UNBUFFERED)
		return (unbuffered_write(buf, len, stream));
	if (!stream->w_base)
	{
		stream->w_base = malloc(_FT_IO_BUFSIZ);
		if (!stream->w_base)
		{
			stream->flags |= _FT_IO_ERR_SEEN;
			return (0);
		}
		stream->w_ptr = stream->w_base;
		stream->w_end = stream->w_base + _FT_IO_BUFSIZ;
	}
	return (ft_io_write_internal(buf, len, stream));
}

static inline size_t	ft_io_write_internal(const void *buf, size_t len,
		t_file *stream)
{
	size_t		result;
	const char	*p;
	const char	*q;
	size_t		tmp;

	p = buf;
	tmp = 0;
	if (stream->flags & _FT_IO_LINE_BUF)
	{
		q = ft_memchr(buf, '\n', len);
		if (q)
			tmp = q - p + 1;
	}
	result = 0;
	if (tmp)
	{
		result = buffered_write(buf, tmp, stream);
		if (ft_fflush(stream) || result != tmp)
			return (result);
	}
	result += buffered_write(buf + tmp, len - tmp, stream);
	return (result);
}

static inline size_t	unbuffered_write(const void *buf, size_t len,
		t_file *stream)
{
	ssize_t	size;

	size = write(stream->fileno, buf, len);
	if (size < 0)
	{
		size = 0;
		stream->flags |= _FT_IO_ERR_SEEN;
	}
	return (size);
}

static inline size_t	buffered_write(const void *buf, size_t len,
		t_file *stream)
{
	ssize_t		size;
	const char	*p;

	p = buf;
	while (len--)
	{
		*stream->w_ptr++ = *p;
		if (stream->w_ptr >= stream->w_end)
		{
			size = write(stream->fileno, stream->w_base, _FT_IO_BUFSIZ);
			if (size < 0)
			{
				stream->flags |= _FT_IO_ERR_SEEN;
				break ;
			}
			stream->w_ptr = stream->w_base;
		}
		p++;
	}
	return (p - (const char *)buf);
}
