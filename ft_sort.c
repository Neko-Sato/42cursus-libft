/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:33:06 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/31 21:26:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(int array[], size_t len)
{
	int		pivot;
	size_t	i;
	size_t	j;

	if (len < 3)
	{
		if (len == 2 && array[0] > array[1])
			swap(&array[0], &array[1]);
		return ;
	}
	pivot = ft_average(array, len);
	i = 0;
	j = len - 1;
	while (i <= j)
	{
		if (array[i] > pivot)
			swap(&array[i], &array[j--]);
		else
			i++;
	}
	ft_sort(&array[0], i);
	ft_sort(&array[i], len - i);
}
