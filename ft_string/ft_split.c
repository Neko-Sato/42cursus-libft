/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:07:34 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/11 21:41:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <ft_vector/ft_vector.h>
#include <stdlib.h>

static inline int	_internal(t_vector *res, const char *s, char c)
{
	const char	delim[] = {c, '\0'};
	char		*copy;
	char		*save;
	char		*tmp;

	copy = ft_strdup(s);
	if (!copy)
		return (1);
	tmp = ft_strtok_r(copy, delim, &save);
	while (tmp)
	{
		tmp = ft_strdup(tmp);
		if (!tmp || ft_vector_push_back(res, &tmp))
			return (free(tmp), free(copy), 1);
		tmp = ft_strtok_r(NULL, delim, &save);
	}
	return (free(copy), ft_vector_push_back(res, &(char *){NULL}));
}

static inline void	_release(t_vector *res)
{
	char	**data;
	size_t	i;

	data = ft_vector_data(res);
	i = ft_vector_size(res);
	while (i)
		free(data[--i]);
	ft_vector_destroy(res);
}

char	**ft_split(const char *s, char c)
{
	t_vector	res;

	ft_vector_init(&res, sizeof(char *));
	if (_internal(&res, s, c))
		return (_release(&res), NULL);
	return (ft_vector_data(&res));
}
