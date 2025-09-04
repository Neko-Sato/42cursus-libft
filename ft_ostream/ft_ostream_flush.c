/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream_flush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:34:13 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/05 00:07:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>

int	ft_ostream_flush(t_ostream *os)
{
	ssize_t	written;
	size_t	pos;
	size_t	size;

	if (os->_lbf == OSTREAM_UNBUF)
		return (0);
	size = os->_pos - os->_buf;
	pos = 0;
	while (!(os->_flags & _OSTREAM_FLAGS_ERROR) && size)
	{
		written = os->_write_fn(&os->_buf[pos], size, os->_arg);
		if (written == -1)
			os->_flags |= _OSTREAM_FLAGS_ERROR;
		else
		{
			size -= written;
			pos += written;
		}
	}
	ft_memcpy(os->_buf, &os->_buf[pos], size);
	os->_pos = &os->_buf[size];
	return (-!(os->_flags & _OSTREAM_FLAGS_ERROR));
}
