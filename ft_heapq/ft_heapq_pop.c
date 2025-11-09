/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapq_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:04:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:16:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heapq/ft_heapq.h>

void	ft_heapq_pop(t_heapq *args)
{
	ft__heapq_swap(args,
		args->base,
		(char *)args->base + args->size * (args->nmemb - 1));
	ft__heapq_shiftdown(&(t_heapq){
		args->base,
		args->nmemb - 1,
		args->size,
		args->less,
		args->swap,
	}, 0);
}
