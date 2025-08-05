/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 07:08:41 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 07:25:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <stdlib.h>

void	*ft_memdup(const void *src, size_t n)
{
	void *dst;

	dst = malloc(n);
	if (!dst)
		return (NULL);
	return (ft_memcpy(dst, src, n));
}
