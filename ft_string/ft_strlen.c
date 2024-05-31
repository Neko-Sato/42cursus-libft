/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:15:06 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/31 22:12:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	static const unsigned long	l_magic = 0x0101010101010101;
	static const unsigned long	h_magic = 0x8080808080808080;
	const char					*ptr;
	const unsigned long			*word_ptr;

	ptr = s;
	while (*ptr && (unsigned long)ptr % sizeof(*word_ptr))
		ptr++;
	if (!*ptr)
		return (ptr - s);
	word_ptr = (void *)ptr;
	while (!((*word_ptr - l_magic) & ~*word_ptr & h_magic))
		word_ptr++;
	return ((char *)ft_memchr(word_ptr, '\0', sizeof(*word_ptr)) - s);
}
