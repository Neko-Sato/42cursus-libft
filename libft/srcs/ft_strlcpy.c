/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:13:37 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/19 11:32:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	int	len;

	len = ft_strlen(src);
	while (1 < dstsize-- && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (len);
}
