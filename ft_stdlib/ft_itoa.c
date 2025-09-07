/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:15:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 12:30:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>

char	*ft_itoa(int n)
{
	char				buf[12];
	t_ostream			os;
	t__write_buffer		wb;
	t__iniprint_args	args;

	wb.buf = buf;
	wb.pos = 0;
	wb.size = sizeof(buf);
	os._write_fn = ft__write_buffer;
	os._arg = &wb;
	os._lbf = OSTREAM_UNBUF;
	os._flags = 0;
	os._buf = NULL;
	os._pos = NULL;
	os._end = NULL;
	args.base = 10;
	args.flags = _INTPRINT_FLAG_SIGNED;
	args.width = -1;
	args.prec = -1;
	ft__intprint(&os, n, &args);
	return (ft_memdup(buf, wb.pos + 1));
}
