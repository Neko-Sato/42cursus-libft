/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:40:17 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/04 23:40:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>

static inline size_t	_write_unbuf(t_ostream *os, const void *buf, size_t n)
{
	ssize_t	written;

	if (os->_flags & _OSTREAM_FLAGS_ERROR)
		return (0);
	written = os->_write_fn(buf, n, os->_arg);
	if (written == -1)
	{
		os->_flags |= _OSTREAM_FLAGS_ERROR;
		return (0);
	}
	return (written);
}

static inline void	_flush_until_line(t_ostream *os)
{
	ssize_t	written;
	size_t	pos;
	char	*lf;

	written = 0;
	pos = 0;
	while (1)
	{
		lf = ft_memchr(&os->_buf[pos], '\n', os->_pos - &os->_buf[pos]);
		if (!lf)
			break ;
		written = os->_write_fn(&os->_buf[pos], lf - &os->_buf[pos] + 1,
				os->_arg);
		if (written == -1)
		{
			os->_flags |= _OSTREAM_FLAGS_ERROR;
			break ;
		}
		pos += written;
	}
	ft_memcpy(os->_buf, &os->_buf[pos], os->_pos - &os->_buf[pos]);
	os->_pos -= pos;
}

static inline size_t	_write_buf(t_ostream *os, const void *buf, size_t n)
{
	size_t	written;
	size_t	remaining;

	remaining = n;
	while (!(os->_flags & _OSTREAM_FLAGS_ERROR) && remaining)
	{
		written = os->_end - os->_pos;
		if (written > remaining)
			written = remaining;
		ft_memcpy(os->_pos, buf, written);
		os->_pos += written;
		remaining -= written;
		buf = (const char *)buf + written;
		if (os->_lbf == OSTREAM_LINEBUF)
			_flush_until_line(os);
		if (os->_pos == os->_end)
			ft_ostream_flush(os);
	}
	return (n - remaining);
}

size_t	ft_ostream_write(t_ostream *os, const void *buf, size_t n)
{
	if (os->_lbf == OSTREAM_UNBUF)
		return (_write_unbuf(os, buf, n));
	else
		return (_write_buf(os, buf, n));
}
