/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:46:47 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/21 18:32:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;
	size_t	haystack_len;
	size_t	needle_len;

	index = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	while (haystack_len < needle_len + index && !ft_strncmp(&haystack[index],
			needle, needle_len))
		index++;
	if (haystack_len < needle_len + index)
		return (NULL);
	return ((char *)&haystack[index]);
}
