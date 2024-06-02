/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:36:42 by hshimizu          #+#    #+#             */
/*   Updated: 2024/06/03 07:39:04 by hshimizu         ###   ########.fr       */
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
		if (c == '\0')
			break ;
		if (buf_chk(lineptr, n, pos))
			return (-1);
		(*lineptr)[pos++] = c;
		if (c == delim)
			break ;
	}
	if (buf_chk(lineptr, n, pos))
		return (-1);
	(*lineptr)[pos] = '\0';
	return (pos);
}

static int	buf_chk(char **lineptr, size_t *n, size_t pos)
{
	static const size_t	default_size = 120;
	size_t				new_size;
	char				*tmp;

	if (!*lineptr || pos >= *n)
	{
		if (!*lineptr || !*n)
			new_size = default_size;
		else
			new_size = *n * 2;
		tmp = malloc(new_size);
		if (!tmp)
			return (-1);
		if (*lineptr)
			ft_memcpy(tmp, *lineptr, pos - 1);
		ft_memswap(&tmp, lineptr, sizeof(char *));
		*n = new_size;
		free(tmp);
	}
	return (0);
}
