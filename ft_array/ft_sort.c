/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:33:06 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:45:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>
#include <ft_string.h>
#include <stddef.h>

void	ft_sort(int array[], size_t len)
{
	int		pivot;
	size_t	i;
	size_t	j;

	if (len < 3)
	{
		if (len == 2 && array[0] > array[1])
			ft_memswap(&array[0], &array[1], sizeof(int));
		return ;
	}
	pivot = ft_average(array, len);
	i = 0;
	j = len - 1;
	while (i <= j)
	{
		if (array[i] > pivot)
			ft_memswap(&array[i], &array[j--], sizeof(int));
		else
			i++;
	}
	ft_sort(&array[0], i);
	ft_sort(&array[i], len - i);
}
