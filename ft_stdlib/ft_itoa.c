/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:15:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/05 23:14:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>

char	*ft_itoa(int n)
{
	char			buf[1024];
	t_ostream		os;
	t__write_buffer	wb;
	t__iniprint_opt	opt;

	wb.buf = buf;
	wb.pos = 0;
	wb.size = sizeof(buf);
	os._write_fn = (ssize_t (*)(const void *, size_t, void *))ft__write_buffer;
	os._arg = &buf;
	opt.width = -1;
	opt.prec = -1;
	opt.flag = _INTPRINT_FLAG_SIGNED;
	ft__intprint(&os, n, 10, &opt);
	return (ft_memdup(buf, wb.pos + 1));
}
