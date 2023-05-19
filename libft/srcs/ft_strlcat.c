/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:16:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/19 11:26:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int	len_dst;
	int	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	while (*src && dstsize-- > len_dst + 1)
		*(dst++ + len_dst) = *src++;
	*(dst + len_dst) = '\0';
	return (len_dst + len_src);
}
