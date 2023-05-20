/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:46:47 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 14:39:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (!big && !len)
		return (NULL);
	little_len = ft_strlen(little);
	while (1)
	{
		if (!ft_strncmp(big++, little, little_len))
			return ((char *)big - 1);
		if (!(*big && len-- > little_len))
			break ;
	}
	return (NULL);
}
