/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:13:44 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/05 21:06:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t n)
{
	static const size_t	word_size = sizeof(unsigned long);
	unsigned char		*ptr;
	unsigned long		*word_ptr;
	unsigned long		c_long;

	ptr = b;
	while (n && (n < word_size || (unsigned long)ptr % word_size))
		*ptr++ = (n--, c);
	if (!n)
		return (b);
	word_ptr = (void *)ptr;
	c_long = (unsigned char)c;
	c_long |= c_long << 8u;
	c_long |= c_long << 16u;
	if (word_size >= 8)
		c_long |= c_long << 32u;
	while (word_size <= n)
	{
		*word_ptr++ = c_long;
		n -= word_size;
	}
	ptr = (unsigned char *)word_ptr;
	while (n)
		*ptr++ = (n--, c);
	return (b);
}
