/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 07:28:48 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 07:29:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t n)
{
	size_t	size;
	char	*ret;

	size = ft_strnlen(src, n) + 1;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, src, size - 1);
	ret[size - 1] = '\0';
	return (ret);
}
