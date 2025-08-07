/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 07:27:04 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:43:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strnlen(src, n);
	ft_strncpy(dst + dst_len, src, src_len);
	dst[dst_len + src_len] = '\0';
	return (dst);
}
