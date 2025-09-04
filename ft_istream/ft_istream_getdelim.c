/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istream_getdelim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:34:10 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/04 23:33:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_istream/ft_istream.h>
#include <ft_string/ft_string.h>
#include <ft_vector/ft_vector.h>

static inline void	_refill(t_istream *is)
{
	ssize_t	res;

	res = is->_read_fn(is->_buf, is->_bufsize, is->_arg);
	if (res == -1)
		is->_flags |= _ISTREAM_FLAGS_ERROR;
	else if (res == 0)
		is->_flags |= _ISTREAM_FLAGS_EOF;
	else
	{
		is->_flags &= ~_ISTREAM_FLAGS_EOF;
		is->_pos = is->_buf;
		is->_end = is->_buf + res;
	}
}

static inline int	_getdelim(t_vector *vec, t_istream *is, char delim)
{
	size_t	size;
	size_t	pos;
	char	*p;

	p = ft_memchr(is->_pos, delim, is->_end - is->_pos);
	if (p)
		size = ++p - is->_pos;
	else
		size = is->_end - is->_pos;
	pos = vec->_size;
	if (ft_vector_resize(vec, vec->_size + size))
		return (-1);
	ft_memcpy(&((char *)vec->_data)[pos], is->_pos, size);
	is->_pos += size;
	return (!!p);
}

static inline int	_internal(t_vector *vec, t_istream *is, char delim)
{
	int	ret;

	vec->_size = 0;
	ret = _getdelim(vec, is, delim);
	if (ret)
		return (ret);
	while (1)
	{
		if (is->_flags & _ISTREAM_FLAGS_ERROR)
			return (-1);
		_refill(is);
		ret = _getdelim(vec, is, delim);
		if (ret)
			return (ret);
		if (is->_flags & _ISTREAM_FLAGS_EOF)
		{
			if (vec->_size)
				return (1);
			return (-1);
		}
	}
}

ssize_t	ft_istream_getdelim(char **lineptr, size_t *n, t_istream *is,
		char delim)
{
	int			ret;
	t_vector	vec;

	vec._data = *lineptr;
	vec._size = 0;
	vec._capa = *n;
	vec._elemsize = sizeof(char);
	ret = _internal(&vec, is, delim);
	if (ret != -1)
	{
		if (ft_vector_resize(&vec, vec._size + 1))
			ret = -1;
		else
			((char *)vec._data)[vec._size - 1] = '\0';
	}
	*lineptr = vec._data;
	*n = vec._capa;
	if (ret == -1)
		return (-1);
	return (vec._size - 1);
}
