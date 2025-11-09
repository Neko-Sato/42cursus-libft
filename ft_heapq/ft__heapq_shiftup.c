/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heapq_shiftup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:31:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:17:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heapq/ft_heapq.h>

void	ft__heapq_shiftup(t_heapq *args, size_t index)
{
	void	*parent;
	void	*child;

	while (index)
	{
		child = (char *)args->base + args->size * index;
		index = (index - 1) / 2;
		parent = (char *)args->base + args->size * index;
		if (!args->less(parent, child))
			break ;
		ft__heapq_swap(args, parent, child);
	}
}
