/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:04:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:34:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>

void	ft_heap_push(t_heap_args *args)
{
	ft__heap_shiftup(&(t_heap_args){
		args->base,
		args->nmemb,
		args->size,
		args->compar,
		args->swap,
	}, args->nmemb - 1);
}
