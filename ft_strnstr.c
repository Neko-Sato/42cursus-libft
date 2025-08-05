/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:17:01 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/05 19:14:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_size;

	needle_size = ft_strlen(needle);
	while (needle_size <= len)
	{
		if (!ft_strncmp(haystack, needle, needle_size))
			return ((char *)haystack);
		if (!*haystack)
			break ;
		(void)(haystack++, len--);
	}
	return (NULL);
}
