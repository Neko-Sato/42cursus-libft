/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:58:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/19 15:10:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (1)
	{
		if (*(s + len) == (char)c)
			return ((char *)(s + len));
		if (!len--)
			break ;
	}
	return (NULL);
}
