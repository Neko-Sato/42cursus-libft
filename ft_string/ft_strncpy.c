/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:37:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/17 20:40:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	size;

	size = ft_strnlen(src, n);
	if (size != n)
		ft_memset(dest + size, '\0', n - size);
	return (ft_memcpy(dest, src, size));
}
