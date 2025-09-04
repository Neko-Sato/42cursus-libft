/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:37:59 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/03 00:08:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <stdlib.h>

int	ft_ostream_init(t_ostream *os, ssize_t (*write_fn)(const void *, size_t,
			void *), void *arg, t_ostream_lbf lbf)
{
	char	*buf;
	size_t	bufsize;

	if (lbf != OSTREAM_UNBUF)
	{
		buf = malloc(_OSTREAM_BUFSIZ);
		if (!buf)
			return (1);
		bufsize = _OSTREAM_BUFSIZ;
	}
	else
	{
		buf = NULL;
		bufsize = 0;
	}
	os->_write_fn = write_fn;
	os->_arg = arg;
	os->_flags = 0;
	os->_lbf = lbf;
	os->_buf = buf;
	os->_bufsize = bufsize;
	os->_pos = buf;
	os->_end = buf + bufsize;
	return (0);
}
