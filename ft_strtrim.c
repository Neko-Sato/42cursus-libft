/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:21:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 17:23:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	c;
	size_t	len;
	char	*result;

	c = *s1;
	while (c && ft_strchr(set, c))
		c = *++s1;
	len = ft_strlen(s1);
	if (len)
	{
		c = *(s1 + len - 1);
		while (c && ft_strchr(set, c))
			c = *(s1 + --len - 1);
	}
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len + 1);
	return (result);
}
