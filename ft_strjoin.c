/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:59:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/05 20:13:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strcpy(char *dst, const char *src)
{
	char *const	head = dst;

	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (head);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(s1 + ft_strlen(s1), s2);
	return (s1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	return (ft_strcat(ft_strcpy(ret, s1), s2));
}
