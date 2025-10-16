/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:37:59 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 17:37:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <stdlib.h>

int	ft_ostream_init(t_ostream *os, t_ostream_init *args)
{
	os->_write_fn = args->write_fn;
	os->_arg = args->arg;
	os->_flags = 0;
	os->_lbf = args->lbf;
	os->_buf = args->buf;
	os->_bufsize = args->bufsize;
	os->_pos = args->buf;
	os->_end = args->buf + args->bufsize;
	return (0);
}
