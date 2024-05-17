/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:37:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/17 20:21:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*end;

	if (!str)
		str = *saveptr;
	if (!*str)
	{
		*saveptr = str;
		return (NULL);
	}
	str += ft_strspn(str, delim);
	if (!*str)
	{
		*saveptr = str;
		return (NULL);
	}
	end = str + ft_strcspn(str, delim);
	if (!*end)
	{
		*saveptr = end;
		return (str);
	}
	*end++ = '\0';
	*saveptr = end;
	return (str);
}
