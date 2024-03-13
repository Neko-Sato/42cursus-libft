/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:37:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/13 20:34:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strtok(char *str, const char *delim)
{
	static char	*old;
	char		*token;

	if (!str)
		str = old;
	str += ft_strspn(str, delim);
	if (!*str)
	{
		old = str;
		return (NULL);
	}
	token = str;
	str = ft_strpbrk(str, delim);
	if (!str)
		old = ft_strchr(token, 0);
	else
	{
		if (*str)
			*str++ = '\0';
		old = str;
	}
	return (token);
}
