/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:55:02 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:56:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*token;

	if (!*stringp)
		return (NULL);
	token = *stringp;
	*stringp += ft_strcspn(*stringp, delim);
	if (**stringp)
		*(*stringp)++ = '\0';
	else
		*stringp = NULL;
	return (token);
}
