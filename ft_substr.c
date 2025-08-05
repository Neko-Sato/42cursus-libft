/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:37:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 00:26:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *s, size_t n)
{
	const char *const	h = s;

	while (n && *s)
		(void)(n--, s++);
	return (s - h);
}

static char	*ft_strndup(const char *src, size_t n)
{
	size_t	size;
	char	*ret;

	size = ft_strnlen(src, n) + 1;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, src, size);
	return (ret);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	return (ft_strndup(s + ft_strnlen(s, start), len));
}
