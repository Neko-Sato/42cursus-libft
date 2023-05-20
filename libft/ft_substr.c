/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:51:01 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/20 13:59:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*result;

	s += start;
	slen = ft_strlen(s);
	if (slen > len)
		slen = len;
	result = (char *)malloc((slen + 1) * sizeof(char));
	if (result)
		ft_strlcpy(result, s, slen + 1);
	return (result);
}
