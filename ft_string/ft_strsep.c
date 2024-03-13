/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:37:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/13 21:03:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*token;

	if (!*stringp)
		return (NULL);
	*stringp += ft_strspn(*stringp, delim);
	if (!**stringp)
	{
		*stringp = NULL;
		return (NULL);
	}
	token = *stringp;
	*stringp = ft_strpbrk(*stringp, delim);
	if (!*stringp || !**stringp)
		*stringp = NULL;
	else
		*(*stringp)++ = '\0';
	return (token);
}
