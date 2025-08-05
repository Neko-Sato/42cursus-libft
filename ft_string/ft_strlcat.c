/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:15:15 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 06:20:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

static size_t	ft_strnlen(const char *s, size_t n)
{
	const char *const	h = s;

	while (n && *s)
		(void)(n--, s++);
	return (s - h);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstcnt;
	size_t	srccnt;

	dstcnt = ft_strnlen(dst, dstsize);
	srccnt = ft_strlen(src);
	dst += dstcnt;
	dstsize -= dstcnt;
	while (1 < dstsize && *src)
		*dst++ = (dstsize--, *src++);
	if (dstsize)
		*dst = 0;
	return (dstcnt + srccnt);
}
