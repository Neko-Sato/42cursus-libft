/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:01:32 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/13 21:04:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	while (*s && !ft_strchr(accept, *s))
		s++;
	if (!*s)
		return (NULL);
	return ((char *)s);
}
