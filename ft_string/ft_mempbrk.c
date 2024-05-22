/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:01:32 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/22 02:26:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

void	*ft_mempbrk(const void *s, size_t n, const void *accept,
		size_t accept_size)
{
	while (n--)
	{
		if (!ft_memchr(accept, *(unsigned char *)s, accept_size))
			return ((void *)s);
		s++;
	}
	return (NULL);
}
