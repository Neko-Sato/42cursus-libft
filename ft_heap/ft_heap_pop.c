/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:04:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 02:58:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>

void	ft_heap_pop(t_heap_args *args)
{
	args->swap(args->base, (char *)args->base + args->size * (args->nmemb - 1));
	ft__heap_shiftdown(&(t_heap_args){
		args->base,
		args->nmemb - 1,
		args->size,
		args->swap,
		args->compar,
	}, 0);
}
