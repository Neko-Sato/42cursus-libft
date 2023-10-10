/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:49:53 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/04 22:25:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnchr(const char *s, int c, size_t n)
{
	while (n--)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (!*s++)
			break ;
	}
	return (NULL);
}
