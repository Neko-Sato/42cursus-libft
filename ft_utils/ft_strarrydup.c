/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrydup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:08:41 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/19 17:27:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "ft_string.h"
#include <stdlib.h>

char	**ft_strarrydup(char *array[])
{
	size_t	i;
	size_t	len;
	char	**new;

	len = ft_arrylen((void *)array);
	new = (char **)malloc((len + 1) * sizeof(char *));
	i = 0;
	while (i < len)
	{
		new[i] = ft_strdup(array[i]);
		if (!new[i++])
		{
			ft_2darraydel(new);
			return (NULL);
		}
	}
	new[i] = NULL;
	return (new);
}
