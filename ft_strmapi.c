/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:21:02 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 01:37:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	char	*tmp;

	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	tmp = ret;
	while (*s)
	{
		*tmp = f(tmp - ret, *s);
		(void)(s++, tmp++);
	}
	*tmp = '\0';
	return (ret);
}
