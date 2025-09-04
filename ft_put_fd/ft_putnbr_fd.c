/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:27:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/02 10:34:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	t_ostream		os;
	t__iniprint_opt	opt;

	os._write_fn = (ssize_t(*)(const void *, size_t, void *))ft__write_fd;
	os._arg = &fd;
	os._lbf = OSTREAM_UNBUF;
	os._buf = NULL;
	os._pos = NULL;
	os._end = NULL;
	opt.width = -1;
	opt.prec = -1;
	opt.flag = _INTPRINT_FLAG_SIGNED;
	ft__intprint(&os, n, 10, &opt);
}
