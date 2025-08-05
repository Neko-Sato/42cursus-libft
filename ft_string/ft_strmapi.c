/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:21:02 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 06:21:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
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
