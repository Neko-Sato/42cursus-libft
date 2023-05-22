/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:22:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/22 13:46:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*_dst;

	if (!dst && !src)
		return (NULL);
	_dst = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (_dst);
}
