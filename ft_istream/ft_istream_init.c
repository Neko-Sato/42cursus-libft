/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:36:29 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 18:29:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <stdlib.h>

int	ft_istream_init(t_istream *is, t_istream_init *args)
{
	char	*buf;
	size_t	bufsize;

	if (!args->buf && !args->bufsize)
	{
		buf = malloc(_ISTREAM_DEFAULT_BUFSIZE);
		if (!buf)
			return (-1);
		bufsize = _ISTREAM_DEFAULT_BUFSIZE;
		is->_flags = _ISTREAM_OWNS_BUF;
	}
	else
	{
		buf = args->buf;
		bufsize = args->bufsize;
		is->_flags = 0;
	}
	is->_read_fn = args->read_fn;
	is->_arg = args->arg;
	is->_buf = buf;
	is->_bufsize = bufsize;
	is->_pos = args->buf;
	is->_end = args->buf;
	return (0);
}
