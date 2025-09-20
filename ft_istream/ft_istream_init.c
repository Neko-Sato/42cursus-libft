/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:36:29 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/20 22:11:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <stdlib.h>

int	ft_istream_init(t_istream *is, ssize_t (*read_fn)(void *, size_t, void *),
		void *arg)
{
	char	*buf;
	size_t	bufsize;

	buf = malloc(_ISTREAM_BUFSIZ);
	if (!buf)
		return (-1);
	bufsize = _ISTREAM_BUFSIZ;
	is->_read_fn = read_fn;
	is->_arg = arg;
	is->_flags = 0;
	is->_buf = buf;
	is->_bufsize = bufsize;
	is->_pos = buf;
	is->_end = buf;
	return (0);
}
