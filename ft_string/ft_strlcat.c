/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:15:15 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 07:31:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

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
