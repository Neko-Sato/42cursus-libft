/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:13:44 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/25 19:13:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned long	*word_ptr;
	unsigned long	c_long;

	ptr = b;
	while (n && (unsigned long)ptr % sizeof(unsigned long))
		*ptr++ = (n--, c);
	if (!n)
		return (b);
	word_ptr = (void *)ptr;
	c_long = (unsigned char)c;
	c_long |= c_long << 8u;
	c_long |= c_long << 16u;
	if (sizeof(*word_ptr) >= 8)
		c_long |= c_long << 32u;
	while (sizeof(*word_ptr) <= n)
	{
		*word_ptr++ = c_long;
		n -= sizeof(*word_ptr);
	}
	ptr = (unsigned char *)word_ptr;
	while (n)
		*ptr++ = (n--, c);
	return (b);
}
