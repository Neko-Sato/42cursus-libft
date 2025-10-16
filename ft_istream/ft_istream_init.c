/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:36:29 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 17:35:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <stdlib.h>

int	ft_istream_init(t_istream *is, t_istream_init *args)
{
	is->_read_fn = args->read_fn;
	is->_arg = args->arg;
	is->_flags = 0;
	is->_buf = args->buf;
	is->_bufsize = args->bufsize;
	is->_pos = args->buf;
	is->_end = args->buf;
	return (0);
}
