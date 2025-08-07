/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:17:01 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 20:17:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

void	*ft_memmem(const void *haystack, size_t haystacklen, const void *needle,
		size_t needlelen)
{
	const unsigned char	*haystack_ptr;

	haystack_ptr = haystack;
	while (needlelen <= haystacklen)
	{
		if (!ft_memcmp(haystack_ptr, needle, needlelen))
			return ((void *)haystack_ptr);
		(void)(haystack_ptr++, haystacklen--);
	}
	return (NULL);
}
