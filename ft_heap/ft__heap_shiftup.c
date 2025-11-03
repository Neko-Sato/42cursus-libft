/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heap_shiftup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:31:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:56:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>

void	ft__heap_shiftup(t_heap_args *args, size_t index)
{
	void	*parent;
	void	*child;

	while (index)
	{
		child = (char *)args->base + args->size * index;
		index = (index - 1) / 2;
		parent = (char *)args->base + args->size * index;
		if (args->compar(parent, child) >= 0)
			break ;
		ft__heap_swap(args, parent, child);
	}
}
