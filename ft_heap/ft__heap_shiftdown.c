/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heap_shiftdown.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:31:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:21:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>

void	ft__heap_shiftdown(t_heap_args *args, size_t index)
{
	size_t	largest;
	size_t	left;
	size_t	right;

	while (1)
	{
		largest = index;
		left = 2 * index + 1;
		right = 2 * index + 2;
		if (left < args->nmemb && args->compar((char *)args->base + args->size
				* largest, (char *)args->base + args->size * left) < 0)
			largest = left;
		if (right < args->nmemb && args->compar((char *)args->base + args->size
				* largest, (char *)args->base + args->size * right) < 0)
			largest = right;
		if (largest == index)
			break ;
		ft__heap_swap(args, (char *)args->base + args->size * largest,
			(char *)args->base + args->size * index);
		index = largest;
	}
}
