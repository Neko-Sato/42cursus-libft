/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferio.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/16 12:55:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFFERIO_H
# define FT_BUFFERIO_H

# include "ft_strgen.h"
# include <unistd.h>

typedef struct s_bufferio
{
	int			fd;
	t_strgen	*strgen;
}				t_bufferio;

t_bufferio		*ft_bufferionew(int fd, size_t buffsize, int close_on_error);
void			ft_bufferiodel(t_bufferio *io, int do_close);
int				ft_bufferioread(t_bufferio *io);
char			*ft_read(t_bufferio *io, int n);
char			*ft_readline(t_bufferio *io);
ssize_t			ft_write(t_bufferio *io, char *str);

#endif
