/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:43:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/08/09 17:58:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_max(int array[], size_t len)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = array[i++];
	while (i < len)
		if (ret < array[i++])
			ret = array[i - 1];
	return (ret);
}
