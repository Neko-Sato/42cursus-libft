/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:09:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/16 18:19:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ISTREAM_H
# define FT_ISTREAM_H

# include <stddef.h>
# include <sys/types.h>

# define _ISTREAM_DEFAULT_BUFSIZE 1024
# define _ISTREAM_FLAGS_ERROR 0x1
# define _ISTREAM_FLAGS_EOF 0x2
# define _ISTREAM_OWNS_BUF 0x100

typedef struct s_istream
{
	ssize_t	(*_read_fn)(void *, size_t, void *);
	void	*_arg;
	int		_flags;
	char	*_buf;
	size_t	_bufsize;
	char	*_pos;
	char	*_end;
}			t_istream;

typedef struct s_istream_init
{
	char	*buf;
	size_t	bufsize;
	ssize_t (*read_fn)(void *, size_t, void *);
	void	*arg;
}			t_istream_init;

int			ft_istream_init(t_istream *is, t_istream_init *args);
void		ft_istream_destroy(t_istream *is);

size_t		ft_istream_read(t_istream *is, void *buf, size_t n);
ssize_t		ft_istream_getdelim(char **lineptr, size_t *n, t_istream *is,
				char delim);
ssize_t		ft_istream_getline(char **lineptr, size_t *n, t_istream *is);
int			ft_istream_error(const t_istream *is);
int			ft_istream_eof(const t_istream *is);

ssize_t		ft__read_fd(void *buf, size_t n, void *arg);

#endif
