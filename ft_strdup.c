/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:34:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 00:49:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
