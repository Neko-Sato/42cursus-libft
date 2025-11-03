/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__heap_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:19:46 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:20:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>
#include <ft_string/ft_string.h>

void	ft__heap_swap(t_heap_args *args, void *a, void *b)
{
	if (args->swap)
		args->swap(a, b);
	else
		ft_memswap(a, b, args->size);
}
