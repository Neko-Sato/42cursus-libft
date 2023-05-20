/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:51:01 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 15:53:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*result;

	slen = ft_strlen(s);
	if (start > slen)
		slen = 0;
	else
		slen -= start;
	s += start;
	if (slen > len)
		slen = len;
	result = (char *)malloc((slen + 1) * sizeof(char));
	if (result)
		ft_strlcpy(result, s, slen + 1);
	return (result);
}
