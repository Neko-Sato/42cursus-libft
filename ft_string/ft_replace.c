/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:07:40 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/21 18:11:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stdlib.h>

char	*ft_replace(const char *s, const char *before, const char *after)
{
	char	*ret;
	char	*temp;
	size_t	size;
	size_t	len[3];

	temp = ft_strstr(s, before);
	if (!temp)
		return (ft_strdup(s));
	len[0] = ft_strlen(s);
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
