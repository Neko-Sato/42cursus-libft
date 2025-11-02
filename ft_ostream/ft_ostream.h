/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostream.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:26:51 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 03:16:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OSTREAM_H
# define FT_OSTREAM_H

# include <stddef.h>
# include <sys/types.h>

# define _OSTREAM_DEFAULT_BUFSIZE 1024
# define _OSTREAM_FLAGS_ERROR 0x1
# define _OSTREAM_OWNS_BUF 0x100

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

typedef struct s_ostream_init
{
	char			*buf;
	size_t			bufsize;
	ssize_t			(*write_fn)(const void *, size_t, void *);
	void			*arg;
	t_ostream_lbf	lbf;
}					t_ostream_init;

int					ft_ostream_init(t_ostream *os, t_ostream_init *args);
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

ssize_t				ft__write_fd(const void *buf, size_t n, void *arg);
ssize_t				ft__write_buffer(const void *buf, size_t n, void *arg);

# define _INTPRINT_FLAG_LEFT_ADJ 0x1
# define _INTPRINT_FLAG_ZERO_PAD 0x2
# define _INTPRINT_FLAG_ALT_FORM 0x4
# define _INTPRINT_FLAG_PAD_POS 0x8
# define _INTPRINT_FLAG_MARK_POS 0x10
# define _INTPRINT_FLAG_SIGNED 0x20
# define _INTPRINT_FLAG_UPPER 0x40

typedef struct s__iniprint_args
{
	unsigned int	base;
	int				flags;
	int				width;
	int				prec;
}					t__iniprint_args;

typedef struct s__iniprint_var
{
	int				neg;
	char			*pos;
	size_t			digit;
	size_t			prec;
	size_t			size;
	size_t			pad;
}					t__iniprint_var;

size_t				ft__intprint(t_ostream *os, unsigned long long n,
						const t__iniprint_args *args);

#endif
