/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__write_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:04:56 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/13 15:42:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>

ssize_t	ft__write_buffer(const void *buf, size_t n, void *arg)
{
	t__write_buffer *const	buffer = arg;
	size_t					size;

	if (!buffer->buf && !buffer->size)
		return (n);
	size = buffer->size - 1;
	if (buffer->pos >= size)
		return (n);
	size -= buffer->pos;
	if (n < size)
		size = n;
	ft_memcpy(buffer->buf + buffer->pos, buf, size);
	buffer->pos += size;
	buffer->buf[buffer->pos] = '\0';
	return (n);
}
