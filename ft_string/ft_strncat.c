/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:00:53 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/17 21:02:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*s;
	size_t	ss;

	s = dest;
	dest += ft_strlen(dest);
	ss = ft_strnlen(src, n);
	dest[ss] = '\0';
	ft_memcpy(dest, src, ss);
	return (s);
}
