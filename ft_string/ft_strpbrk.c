/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:35:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:41:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	size_t	accept_len;

	accept_len = ft_strlen(accept);
	while (1)
	{
		if (ft_memchr(accept, *s, accept_len))
			return ((char *)s);
		if (!*s)
			break ;
		s++;
	}
	return (NULL);
}
