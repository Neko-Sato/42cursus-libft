/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:34:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 06:20:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(s) + 1;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s, size);
	return (ret);
}
