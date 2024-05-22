/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferio.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/23 01:36:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFERIO_H
# define FT_BUFFERIO_H

# include <unistd.h>

# ifndef BUFFERIO_DEFAULT_BUFFERSIZE
#  define BUFFERIO_DEFAULT_BUFFERSIZE 0x400
# endif

typedef struct s_bufferio
{
	int		_fd;
	size_t	_len;
	size_t	_capacity;
	size_t	_pos;
	char	*_buf;
}			t_bufferio;

int			ft_bufferio_resize(t_bufferio *io, size_t capacity);
int			ft_bufferio_read(t_bufferio *io, size_t size);

t_bufferio	*ft_open(int fd, int close_on_close);
void		ft_close(t_bufferio *io, int do_close);
ssize_t		ft_read(t_bufferio *io, char *buf, size_t size);
ssize_t		ft_write(t_bufferio *io, char *buf, size_t size);

int			ft_getline(char **line, t_bufferio *io);

#endif
