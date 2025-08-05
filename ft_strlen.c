/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:46:37 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/28 10:57:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	static const size_t			word_size = sizeof(unsigned long);
	static const unsigned long	l_magic = 0x0101010101010101;
	static const unsigned long	h_magic = 0x8080808080808080;
	const char					*ptr;
	const unsigned long			*word_ptr;

	ptr = s;
	while (*ptr && (unsigned long)ptr % word_size)
		ptr++;
	if (!*ptr)
		return (ptr - s);
	word_ptr = (void *)ptr;
	while (!((*word_ptr - l_magic) & ~*word_ptr & h_magic))
		word_ptr++;
	ptr = (void *)word_ptr;
	while (*ptr)
		ptr++;
	return (ptr - s);
}
