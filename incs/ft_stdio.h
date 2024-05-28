/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 02:00:05 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 05:34:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <sys/types.h>

/*
	This is a lightweight version of stdio
	and differs in some respects from the original.
	It is not thread-safe and does not auto-close.
*/

# define FT_EOF -1

# define _FT_IO_BUFSIZ 0x2000

# define _FT_IOFBF 0
# define _FT_IOLBF 1
# define _FT_IONBF 2

# define _FT_IO_EOF_SEEN 0b01
# define _FT_IO_ERR_SEEN 0b10

# define _FT_IO_UNBUFFERED 0b0100
# define _FT_IO_LINE_BUF 0x01000

# define _FT_IO_NO_READS 0b010000
# define _FT_IO_NO_WRITES 0b100000

# define _FT_IO_DELETE_DONT_CLOSE 0b1000000

typedef struct s_file
{
	int		fileno;
	int		flags;
	char	*r_base;
	char	*r_ptr;
	char	*r_end;
	char	*w_base;
	char	*w_ptr;
	char	*w_end;
}			t_file;

t_file		*ft_file_new(int fd, int rw, int wbuftype, int do_close);
int			ft_fclose(t_file *stream);

void		ft_clearerr(t_file *stream);
int			ft_feof(t_file *stream);
int			ft_ferror(t_file *stream);
int			ft_fileno(t_file *stream);

size_t		ft_io_read(void *buf, size_t len, t_file *stream);
size_t		ft_io_write(const void *buf, size_t len, t_file *stream);

int			ft_getc(t_file *stream);
int			ft_ungetc(int c, t_file *stream);
int			ft_putc(int c, t_file *stream);

int			ft_fflush(t_file *stream);

int			ft_fgetc(t_file *stream);
char		*ft_fgets(char *s, int sidze, t_file *stream);
int			ft_fputc(int c, t_file *stream);
int			ft_fputs(const char *s, t_file *stream);

size_t		ft_fread(void *ptr, size_t size, size_t nmemb, t_file *stream);
size_t		ft_fwrite(const void *ptr, size_t size, size_t nmemb,
				t_file *stream);

ssize_t		ft_getdelim(char **lineptr, size_t *n, int delim, t_file *stream);
ssize_t		ft_getline(char **lineptr, size_t *n, t_file *stream);

#endif
