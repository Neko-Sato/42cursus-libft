/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:34:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 20:40:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	clean(char **array, size_t i);

void	*ft_2darraynew(size_t size, size_t width, size_t height)
{
	char	**array;
	size_t	n[2];
	size_t	i;

	n[0] = sizeof(void *) * (width + 1);
	n[1] = size * height;
	if (n[0] / sizeof(void *) != (width + 1) || n[1] / size != height)
		return (NULL);
	array = malloc(n[0]);
	if (!array)
		return (NULL);
	i = 0;
	while (i < width)
	{
		array[i] = malloc(n[1]);
		if (!array[i++])
		{
			clean(array, --i);
			return (NULL);
		}
	}
	array[i] = NULL;
	return (array);
}

static void	clean(char **array, size_t i)
{
	while (i--)
		free(array[i]);
	free(array);
}
