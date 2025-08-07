/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:14:51 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:12:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnchr(const char *s, int c, size_t n)
{
	while (n)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s)
			break ;
		(void)(n--, s++);
	}
	return (NULL);
}
