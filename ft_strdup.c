/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:38:26 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/26 17:46:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*_s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size * sizeof(char));
	_s2 = s2;
	if (s2)
		while (size--)
			*s2++ = *s1++;
	return (_s2);
}
