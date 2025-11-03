/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heapify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 01:28:14 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 14:28:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_heapq/ft_heapq.h>

void	ft_heapify(t_heapq *args)
{
	size_t	n;

	n = args->nmemb / 2;
	while (n)
		ft__heapq_shiftdown(args, --n);
}
