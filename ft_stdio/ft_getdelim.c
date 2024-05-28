/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:36:42 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 05:54:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <ft_string.h>
#include <stdlib.h>
#include <unistd.h>

static int	buf_chk(char **lineptr, size_t *n, size_t pos);

ssize_t	ft_getdelim(char **lineptr, size_t *n, int delim, t_file *stream)
{
	int		c;
	size_t	pos;

	pos = 0;
	while (1)
	{
		c = ft_getc(stream);
		if (c == FT_EOF)
		{
			if (ft_ferror(stream) || !pos)
				return (-1);
			break ;
		}
		if (buf_chk(lineptr, n, pos))
			return (-1);
		(*lineptr)[pos] = c;
		if (!c || c == delim)
			break ;
		pos++;
	}
	if ((*lineptr)[pos])
		if (buf_chk(lineptr, n, ++pos))
			return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}

static int	buf_chk(char **lineptr, size_t *n, size_t pos)
{
	char	*tmp;

	if (!*lineptr || !*n)
	{
		*lineptr = malloc(120);
		if (!*lineptr)
			return (-1);
		*n = 120;
		return (0);
	}
	if (pos >= *n)
	{
		tmp = malloc(*n * 2);
		if (!tmp)
			return (-1);
		*n *= 2;
		ft_memcpy(tmp, *lineptr, pos - 1);
		ft_memswap(tmp, *lineptr, sizeof(char *));
		free(tmp);
	}
	return (0);
}
