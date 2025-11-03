/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:31:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils/ft_utils.h>

static void	_swap(t_sort *args, void *a, void *b)
{
	if (args->swap)
		args->swap(a, b);
	else
		ft_memswap(a, b, args->size);
}

static inline void	_case_pair(t_sort *args)
{
	void	*obj[2];

	obj[0] = args->base;
	obj[1] = (char *)args->base + args->size;
	if (args->nmemb == 2 && args->compar(obj[0], obj[1]) > 0)
		_swap(args, obj[0], obj[1]);
}

static inline size_t	_partition(t_sort *args)
{
	void	*current;
	void	*pivot;
	size_t	i;
	size_t	j;

	pivot = (char *)args->base + args->size * (args->nmemb - 1);
	i = 0;
	j = 0;
	while (j < args->nmemb - 1)
	{
		current = (char *)args->base + args->size * j;
		if (args->compar(current, pivot) <= 0)
			_swap(args, current, (char *)args->base + args->size * i++);
		j++;
	}
	_swap(args, (char *)args->base + args->size * i, pivot);
	return (i);
}

void	*ft_sort(t_sort *args)
{
	size_t	pi;

	if (args->nmemb == 0)
		;
	else if (args->nmemb < 3)
		_case_pair(args);
	else
	{
		pi = _partition(args);
		ft_sort(&(t_sort){args->base, pi, args->size, args->compar});
		ft_sort(&(t_sort){(char *)args->base + (pi + 1) * args->size,
			args->nmemb - (pi + 1), args->size, args->compar});
	}
	return (args->base);
}
