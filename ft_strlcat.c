/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:15:15 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/25 18:15:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOT_LOCAL_LIBFT
# include "libft.h"
#else
# include <libft.h>
#endif

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
