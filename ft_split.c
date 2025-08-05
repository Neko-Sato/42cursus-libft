/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:07:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 00:38:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static inline size_t	__count_words(const char *s, int c)
{
	int		in_words;
	size_t	cnt;

	in_words = 0;
	cnt = 0;
	while (*s)
	{
		while (*s && (*s == (char)c) != in_words)
			s++;
		if (in_words)
			cnt++;
		in_words = !in_words;
	}
	return (cnt);
}

static inline int	__assign_words(const char *s, int c, char **ret)
{
	char **const		head = ret;
	int					in_words;
	const char			*start;

	in_words = 0;
	start = NULL;
	while (*s)
	{
		while (*s && (*s == (char)c) != in_words)
			s++;
		if (in_words)
			start = s;
		else
		{
			*ret = ft_substr(start, 0, s - start);
			if (!*ret)
			{
				while (head != ret)
					free(*--ret);
				return (1);
			}
		}
		in_words = !in_words;
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	size;

	size = __count_words(s, c) + 1;
	ret = malloc(sizeof(char *) * size);
	if (!ret)
		return (NULL);
	if (__assign_words(s, c, ret))
	{
		free(ret);
		return (NULL);
	}
	ret[size - 1] = NULL;
	return (ret);
}
