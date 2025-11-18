/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:27:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 04:32:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <unistd.h>

void	ft_putbin_fd(int n, int fd)
{
	t_ostream			os;
	char				buf[1024];
	t__iniprint_args	args;

	ft_ostream_init(&os, &(t_ostream_init){
		buf, sizeof(buf), ft__write_fd, &fd, OSTREAM_FULLBUF
	});
	args.base = 2;
	args.flags = _INTPRINT_FLAG_SIGNED;
	args.width = -1;
	args.prec = -1;
	ft_ostream_write(&os, "0b", 2);
	ft__intprint(&os, n, &args);
	ft_ostream_destroy(&os);
}
