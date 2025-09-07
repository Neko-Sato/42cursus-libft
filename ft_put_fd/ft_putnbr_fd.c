/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:27:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/07 12:30:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	t_ostream			os;
	t__iniprint_args	args;

	os._write_fn = ft__write_fd;
	os._arg = &fd;
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
}
