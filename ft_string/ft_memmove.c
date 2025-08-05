/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:12:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/07/25 18:13:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*udst;
	const unsigned char	*usrc;

	udst = dst;
	usrc = src;
	if (dst < src)
	{
		while (n)
			*udst++ = (n--, *usrc++);
	}
	else
	{
		udst += n;
		usrc += n;
		while (n)
			*--udst = (n--, *--usrc);
	}
	return (dst);
}
