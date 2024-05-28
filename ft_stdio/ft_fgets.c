/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:54:47 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 05:35:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stddef.h>

char	*ft_fgets(char *s, int size, t_file *stream)
{
	int		i;
	char	c;

	if (!s || size <= 0)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		c = ft_getc(stream);
		if (c == FT_EOF)
		{
			if (ft_ferror(stream))
				return (NULL);
			break ;
		}
		s[i] = c;
		if (c == '\n' || c == '\0')
			break ;
		i++;
	}
	if (s[i])
		s[++i] = '\0';
	return (s);
}
