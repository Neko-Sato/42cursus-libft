/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heapq_shiftdown.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:31:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:18:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heapq/ft_heapq.h>

void	ft__heapq_shiftdown(t_heapq *args, size_t index)
{
	size_t	largest;
	size_t	left;
	size_t	right;

	while (1)
	{
		largest = index;
		left = 2 * index + 1;
		right = 2 * index + 2;
		if (left < args->nmemb && args->less((char *)args->base + args->size
				* largest, (char *)args->base + args->size * left))
			largest = left;
		if (right < args->nmemb && args->less((char *)args->base + args->size
				* largest, (char *)args->base + args->size * right))
			largest = right;
		if (largest == index)
			break ;
		ft__heapq_swap(args, (char *)args->base + args->size * largest,
			(char *)args->base + args->size * index);
		index = largest;
	}
}
