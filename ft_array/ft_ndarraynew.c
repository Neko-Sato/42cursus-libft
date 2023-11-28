/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndarraynew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:30:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 21:28:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>
#include <stdlib.h>

void	*ft_ndarraynew(size_t size, size_t shape[], size_t ndim)
{
	void	*array;
	size_t	i;

	if (!ndim)
		return (NULL);
	else if (ndim <= 1)
		return (malloc(size * shape[0]));
	array = malloc(sizeof(void *) * (shape[0] + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < shape[0])
	{
		((void **)array)[i] = ft_ndarraynew(size, &shape[1], ndim - 1);
		if (!((void **)array)[i])
		{
			while (i--)
				ft_ndarraydel(((void **)array)[i], ndim - 1);
			free(array);
			return (NULL);
		}
		i++;
	}
	((void **)array)[i] = NULL;
	return (array);
}
