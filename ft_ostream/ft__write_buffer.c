/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__write_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:04:56 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/02 08:43:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ostream/ft_ostream.h>
#include <ft_string/ft_string.h>

ssize_t	ft__write_buffer(const void *buf, size_t n, t__write_buffer *buffer)
{
	size_t	size;

	if (!buffer->buf && !buffer->size)
		return (n);
	if (buffer->pos >= buffer->size)
		return (n);
	size = buffer->size - buffer->pos;
	if (n < size)
		size = n;
	ft_memcpy(buffer->buf + buffer->pos, buf, size);
	buffer->pos += size;
	if (buffer->pos < buffer->size)
		buffer->buf[buffer->pos] = '\0';
	return (n);
}
