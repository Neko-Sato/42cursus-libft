/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:13:37 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/16 23:16:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	n;

	n = ft_strlen(src);
	while (1 < size-- && *src)
		*(dest++) = *(src++);
	*dest = '\0';
	return (n);
}
