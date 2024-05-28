/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:45:10 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 06:13:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
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
	f->fileno = fd;
	f->flags = 0;
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
	f->r_base = NULL;
	f->r_ptr = NULL;
	f->r_base = NULL;
	f->w_base = NULL;
	f->w_ptr = NULL;
	f->w_end = NULL;
	return (f);
}
