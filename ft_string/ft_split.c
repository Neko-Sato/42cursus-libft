/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:07:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 14:38:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <stdlib.h>

static inline size_t	_count_words(const char *s, int c)
{
	int		in_words;
	size_t	cnt;

	in_words = 0;
	cnt = 0;
	while (*s)
	{
		while (*s && (*s != (char)c) == in_words)
			s++;
		if (in_words)
			cnt++;
		in_words = !in_words;
	}
	return (cnt);
}

static inline void	_assign_error(char **head, char **tmp)
{
	while (head != tmp)
		free(*--tmp);
}

static inline int	_assign_words(const char *s, int c, char **ret)
{
	char **const		head = ret;
	int					in_words;
	const char			*start;

	in_words = 0;
	while (*s)
	{
		while (*s && (*s != (char)c) == in_words)
			s++;
		if (in_words)
		{
			*ret = ft_substr(start, 0, s - start);
			if (!*ret)
				return (_assign_error(head, ret), 1);
			ret++;
		}
		else
			start = s;
		in_words = !in_words;
	}
	*ret = NULL;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	size;

	size = _count_words(s, c) + 1;
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (NULL);
	if (_assign_words(s, c, ret))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
