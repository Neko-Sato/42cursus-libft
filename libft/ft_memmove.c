/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:22:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 14:29:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*_dst;
	int		direction;

	if (!dst && !src)
		return (NULL);
	_dst = dst;
	direction = 1;
	if (dst > src)
	{
		direction = -1;
		dst += len - 1;
		src += len - 1;
	}
	while (len--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst += direction;
		src += direction;
	}
	return (_dst);
}
