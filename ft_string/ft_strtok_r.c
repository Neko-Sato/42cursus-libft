/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:37:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/17 19:20:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*token;

	if (!str)
		str = *saveptr;
	str += ft_strspn(str, delim);
	if (!*str)
	{
		*saveptr = str;
		return (NULL);
	}
	token = str;
	str = ft_strpbrk(str, delim);
	if (!str)
		*saveptr = ft_strchr(token, 0);
	else
	{
		if (*str)
			*str++ = '\0';
		*saveptr = str;
	}
	return (token);
}
