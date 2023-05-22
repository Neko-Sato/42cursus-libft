/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:22:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/22 18:09:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*_dst;
	const unsigned char	*_src;

	if (!dst && !src)
		return (NULL);
	_dst = dst;
	_src = src;
	while (n--)
		*_dst++ = *_src++;
	return (dst);
}
