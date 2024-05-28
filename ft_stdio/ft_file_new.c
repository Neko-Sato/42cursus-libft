/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:45:10 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 06:17:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdio.h>
#include <stdlib.h>

t_file	*ft_file_new(int fd, int rw, int wbuftype, int do_close)
{
	t_file	*f;

	if (fd < 0)
		return (NULL);
	f = malloc(sizeof(*f));
	if (!f)
		return (NULL);
	ft_memset(f, 0, sizeof(*f));
	f->fileno = fd;
	if (!(rw & 0b10))
		f->flags |= _FT_IO_NO_READS;
	if (!(rw & 0b01))
		f->flags |= _FT_IO_NO_WRITES;
	if (wbuftype == _FT_IOLBF)
		f->flags |= _FT_IO_LINE_BUF;
	else if (wbuftype == _FT_IONBF)
		f->flags |= _FT_IO_UNBUFFERED;
	if (!do_close)
		f->flags |= _FT_IO_DELETE_DONT_CLOSE;
	return (f);
}
