/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:08:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/27 10:00:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_string.h>
#include <unistd.h>

static int	read_until_line(t_bufferio *io, size_t *size);

char	*ft_readline(t_bufferio *io)
{
	char	*result;
	int		ret;
	size_t	size;

	ret = read_until_line(io, &size);
	if (ret == -1 || !io->_len)
		return (NULL);
	result = ft_strndup(&io->_buf[io->_pos], size);
	if (!result)
		return (NULL);
	io->_pos += size;
	io->_len -= size;
	return (result);
}

static int	read_until_line(t_bufferio *io, size_t *size)
{
	int ret;
	char *enter;
	size_t tmp;

	tmp = 0;
	while (1)
	{
		enter = ft_strnchr(&io->_buf[tmp], '\n', io->_len - tmp);
		if (enter)
			break ;
		tmp = io->_len;
		ret = ft_bufferio_read(io, io->_capacity * 1.5);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			break ;
	}
	if (enter)
		*size = enter - &io->_buf[io->_pos];
	else
		*size = io->_len;
	return (0);
}