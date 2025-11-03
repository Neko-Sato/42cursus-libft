/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapq_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 02:04:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 14:28:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heapq/ft_heapq.h>

void	ft_heapq_push(t_heapq *args)
{
	ft__heapq_shiftup(&(t_heapq){
		args->base,
		args->nmemb,
		args->size,
		args->compar,
		args->swap,
	}, args->nmemb - 1);
}
