/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:46:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/21 16:35:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle++)
	{
		needle_len = ft_strlen(needle);
		while (1)
		{
			while (1)
			{
				if (len-- < 1 || !*haystack++)
					return (NULL);
				if (*(haystack - 1) == *(needle - 1))
					break ;
			}
			if (needle_len > len)
				return (NULL);
			if (!ft_strncmp(haystack, needle, needle_len))
				break ;
		}
		haystack--;
	}
	return ((char *)haystack);
}
