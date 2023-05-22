/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:16:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/22 13:46:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (maxlen-- && *s++)
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strnlen(dst, dstsize);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	while (*src && dstsize-- > len_dst + 1)
		*(dst++ + len_dst) = *src++;
	*(dst + len_dst) = '\0';
	return (len_dst + len_src);
}
