/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 01:28:14 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 03:04:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heap/ft_heap.h>

void	ft_heapify(t_heap_args *args)
{
	size_t	n;

	n = args->nmemb / 2;
	while (n)
		ft__heap_shiftdown(args, --n);
}
