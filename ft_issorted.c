/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 07:20:28 by hshimizu          #+#    #+#             */
/*   Updated: 2023/08/01 07:30:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_issorted(int array[], size_t len, int asc)
{
	int		ret;
	size_t	i;

	ret = 1;
	i = 1;
	while (ret && i < len)
	{
		if (asc)
			ret &= (array[i - 1] <= array[i]);
		else
			ret &= (array[i - 1] >= array[i]);
	}
	return (ret);
}
