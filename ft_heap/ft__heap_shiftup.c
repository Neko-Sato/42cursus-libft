/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heap_shiftup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:31:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:27:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>

void	ft__heap_shiftup(t_heap_args *args, size_t index)
{
	size_t	parent;

	while (index)
	{
		parent = (index - 1) / 2;
		if (args->compar(
				(char *)args->base + args->size * parent,
				(char *)args->base + args->size * index) >= 0)
			break ;
		ft__heap_swap(args,
			(char *)args->base + args->size * parent,
			(char *)args->base + args->size * index);
		index = parent;
	}
}
