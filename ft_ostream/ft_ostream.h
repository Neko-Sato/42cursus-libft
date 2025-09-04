/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:26:51 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/03 00:07:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OSTREAM_H
# define FT_OSTREAM_H

# include <stddef.h>
# include <sys/types.h>

# define _OSTREAM_BUFSIZ 1024
# define _OSTREAM_FLAGS_ERROR 0x1

typedef enum s_ostream_lbf
{
	OSTREAM_UNBUF,
	OSTREAM_LINEBUF,
	OSTREAM_FULLBUF
}					t_ostream_lbf;

typedef struct s_ostream
{
	ssize_t			(*_write_fn)(const void *, size_t, void *);
	void			*_arg;
	int				_flags;
	t_ostream_lbf	_lbf;
	char			*_buf;
	size_t			_bufsize;
	char			*_pos;
	char			*_end;
}					t_ostream;

int					ft_ostream_init(t_ostream *os,
						ssize_t (*write_fn)(const void *, size_t, void *),
						void *arg, t_ostream_lbf lbf);
void				ft_ostream_destroy(t_ostream *os);

size_t				ft_ostream_write(t_ostream *os, const void *buf, size_t n);
int					ft_ostream_flush(t_ostream *os);
int					ft_ostream_error(const t_ostream *os);

typedef struct s__write_buffer
{
	char			*buf;
	size_t			size;
	size_t			pos;
}					t__write_buffer;

ssize_t				ft__write_fd(const void *buf, size_t n, int *fd);
ssize_t				ft__write_buffer(const void *buf, size_t n,
						t__write_buffer *buffer);

# define _INTPRINT_FLAG_LEFT_ADJ 0x1
# define _INTPRINT_FLAG_ZERO_PAD 0x2
# define _INTPRINT_FLAG_ALT_FORM 0x4
# define _INTPRINT_FLAG_PAD_POS 0x8
# define _INTPRINT_FLAG_MARK_POS 0x10
# define _INTPRINT_FLAG_SIGNED 0x20
# define _INTPRINT_FLAG_UPPER 0x40

typedef struct s__iniprint_opt
{
	int				flag;
	int				width;
	int				prec;
}					t__iniprint_opt;

ssize_t				ft__intprint(t_ostream *os, unsigned long long n,
						unsigned int base, const t__iniprint_opt *opt);

#endif
