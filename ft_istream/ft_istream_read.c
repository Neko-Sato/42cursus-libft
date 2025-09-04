/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:19:09 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/04 23:40:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <ft_string/ft_string.h>

static inline void	_refill(t_istream *is)
{
	ssize_t	res;

	res = is->_read_fn(is->_buf, is->_bufsize, is->_arg);
	if (res == -1)
		is->_flags |= _ISTREAM_FLAGS_ERROR;
	else if (res == 0)
		is->_flags |= _ISTREAM_FLAGS_EOF;
	else
	{
		is->_flags &= ~_ISTREAM_FLAGS_EOF;
		is->_pos = is->_buf;
		is->_end = is->_buf + res;
	}
}

static inline void	_from_buffer(t_istream *is, void **buf, size_t *remaining)
{
	size_t	size;

	size = is->_end - is->_pos;
	if (*remaining < size)
		size = *remaining;
	ft_memcpy(*buf, is->_pos, size);
	is->_pos += size;
	*buf = *(char **)buf + size;
	*remaining -= size;
}

static inline void	_directly(t_istream *is, void **buf, size_t *remaining)
{
	ssize_t	res;

	res = is->_read_fn(*buf, *remaining, is->_arg);
	if (res == -1)
		is->_flags |= _ISTREAM_FLAGS_ERROR;
	else if (res == 0)
		is->_flags |= _ISTREAM_FLAGS_EOF;
	else
	{
		is->_flags &= ~_ISTREAM_FLAGS_EOF;
		*buf = *(char **)buf + res;
		*remaining -= res;
	}
}

size_t	ft_istream_read(t_istream *is, void *buf, size_t n)
{
	size_t	remaining;

	remaining = n;
	if (is->_end != is->_pos)
		_from_buffer(is, &buf, &remaining);
	while (remaining)
	{
		if (is->_flags & _ISTREAM_FLAGS_ERROR)
			break ;
		if (remaining < is->_bufsize)
		{
			_refill(is);
			_from_buffer(is, &buf, &remaining);
		}
		else
			_directly(is, &buf, &remaining);
		if (is->_flags & _ISTREAM_FLAGS_EOF)
			break ;
	}
	return (n - remaining);
}
