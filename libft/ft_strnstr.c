/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:46:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 23:42:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	while (*big && len-- >= little_len)
	{
		if (!ft_strncmp(big++, little, little_len))
			return ((char *)big - 1);
	}
	return (NULL);
}

#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *a, *b;
	a = ft_strnstr("", "", 0);
	b = strnstr("", "", 0);
}