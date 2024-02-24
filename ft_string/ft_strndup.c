/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:38:26 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/24 13:56:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	if (n < size)
		size = n;
	s2 = (char *)malloc(size * sizeof(char));
	ft_strlcpy(s2, s1, size);
	return (s2);
}
