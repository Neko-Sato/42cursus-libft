/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:17:01 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:45:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_size;

	needle_size = ft_strlen(needle);
	while (1)
	{
		if (!ft_strncmp(haystack, needle, needle_size))
			return ((char *)haystack);
		if (!*haystack)
			break ;
		haystack++;
	}
	return (NULL);
}
