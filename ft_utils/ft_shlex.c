/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shlex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 03:11:52 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/20 07:41:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>
#include <ft_string.h>
#include <stddef.h>

/*
	Follows the posix mode of shlex in Python's standard library.
	Use it akin to strsep.
	And, of course, make destructive changes.
*/

static char	*skip_blank(char *s, int comments);
static char	*skip_word(char *s, int comments, int *error);
static void	expand_word(char *s);

char	*ft_shlex(char **stringp, int comments, int *error)
{
	char	*s;
	char	*head;

	*error = 0;
	s = *stringp;
	s = skip_blank(s, comments);
	if (!*s)
		return (NULL);
	head = s;
	s = skip_word(s, comments, error);
	if (*error)
		return (NULL);
	expand_word(head);
	*stringp = s;
	return (head);
}

static char	*skip_blank(char *s, int comments)
{
	while (1)
	{
		while (*s && (ft_isblank(*s) || *s == '\n'))
			s++;
		if (!comments || *s != '#')
			return (s);
		while (*s && *s != '\n')
			s++;
	}
}

static char	*skip_word(char *s, int comments, int *error)
{
	int	c;

	while (*s && !(ft_isblank(*s) || *s == '\n') && !(comments && *s == '#'))
	{
		c = *s++;
		if (ft_strnchr("'\"", c, 2))
		{
			while (*s && *s != c)
				if (*s++ == '\\' && c == '"' && *s)
					s++;
		}
		else if (c != '\\')
			continue ;
		if (*s)
			s++;
		else
			*error = 1;
	}
	c = *s;
	if (*s)
		*s++ = '\0';
	if (comments && c == '#')
		while (*s && *s != '\n')
			s++;
	return (s);
}

static void	expand_word(char *s)
{
	char	*g;
	int		c;

	g = s;
	while (*s)
	{
		c = *s;
		if (c == '\\')
			s++;
		else if (ft_strnchr("'\"", c, 2))
		{
			s++;
			while (*s != c)
				*g++ = *s++;
			s++;
		}
		else
			*g++ = *s++;
	}
	while (*g)
		*g++ = '\0';
}
