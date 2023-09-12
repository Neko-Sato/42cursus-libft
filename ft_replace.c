/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:07:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:23:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_replace(const char *s, const char *before, const char *after)
{
	char	*ret;
	char	*temp;
	size_t	size;
	size_t	len[3];

	len[0] = ft_strlen(s);
	temp = ft_strnstr(s, before, len[0]);
	if (!temp)
		return (ft_strdup(s));
	len[1] = ft_strlen(before);
	len[2] = ft_strlen(after);
	size = len[0] - len[1] + len[2] + 1;
	ret = (char *)malloc(size * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, temp - s + 1);
	ft_strlcat(ret, after, temp - s + len[2] + 1);
	ft_strlcat(ret, temp + len[1], size);
	return (ret);
}
