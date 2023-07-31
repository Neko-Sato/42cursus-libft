/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_average.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:42:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/31 21:31:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_average(int array[], size_t len)
{
	size_t	i;
	double	n;

	n = 0;
	i = 0;
	while (i < len)
		n += array[i++] / (double)len;
	return ((int)n);
}
