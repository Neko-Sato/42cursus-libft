/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:45:10 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 17:25:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_file	*ft_file_new(int fd, int rw, int wbuftype, int do_close)
{
	t_file	*f;

	if (fd < 0)
		return (NULL);
	f = malloc(sizeof(*f));
	if (!f)
	{
		if (do_close)
			close(fd);
		return (NULL);
	}
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

// t_file	*g_ft_stdin = NULL;
// t_file	*g_ft_stdout = NULL;
// t_file	*g_ft_stderr = NULL;

// __attribute__((constructor))
// int	__libft_init_stdio(void)
// {
// 	g_ft_stdin = ft_file_new(STDIN_FILENO, 0b10, 0, 0);
// 	g_ft_stdout = ft_file_new(STDOUT_FILENO, 0b01, _FT_IOLBF, 0);
// 	g_ft_stderr = ft_file_new(STDERR_FILENO, 0b01, _FT_IONBF, 0);
// 	return (0);
// }

// __attribute__((destructor))
// int	__libft_fini_stdio(void)
// {
// 	ft_fclose(g_ft_stderr);
// 	ft_fclose(g_ft_stdout);
// 	ft_fclose(g_ft_stdin);
// 	return (0);
// }
