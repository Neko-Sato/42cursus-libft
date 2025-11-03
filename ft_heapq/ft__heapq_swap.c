/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heapq_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:19:46 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 14:29:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heapq/ft_heapq.h>
#include <ft_string/ft_string.h>

void	ft__heapq_swap(t_heapq *args, void *a, void *b)
{
	if (args->swap)
		args->swap(a, b);
	else
		ft_memswap(a, b, args->size);
}
