/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 17:56:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>

void	*ft_bsearch(t_bsearch *args)
{
	size_t		low;
	size_t		high;
	size_t		mid;
	const void	*element;
	int			res;

	if (args->n == 0)
		return (NULL);
	low = 0;
	high = args->n - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		element = (const unsigned char *)args->base + mid * args->size;
		res = args->compar(args->key, element);
		if (res < 0)
			high = mid - 1;
		else if (res > 0)
			low = mid + 1;
		else
			return ((void *)element);
	}
	return (NULL);
}
