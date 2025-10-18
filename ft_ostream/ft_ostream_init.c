/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:37:59 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/18 10:22:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <stdlib.h>

int	ft_ostream_init(t_ostream *os, t_ostream_init *args)
{
	char	*buf;
	size_t	bufsize;

	if (!args->buf && !args->bufsize && args->lbf != OSTREAM_UNBUF)
	{
		buf = malloc(_OSTREAM_DEFAULT_BUFSIZE);
		if (!buf)
			return (-1);
		bufsize = _OSTREAM_DEFAULT_BUFSIZE;
		os->_flags = _OSTREAM_OWNS_BUF;
	}
	else
	{
		buf = args->buf;
		bufsize = args->bufsize;
		os->_flags = 0;
	}
	os->_write_fn = args->write_fn;
	os->_arg = args->arg;
	os->_lbf = args->lbf;
	os->_buf = buf;
	os->_bufsize = bufsize;
	os->_pos = args->buf;
	os->_end = args->buf + args->bufsize;
	return (0);
}
