/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:51:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils/ft_utils.h>
#include <ft_string/ft_string.h>

static void	_swap(t__sort *args, void *a, void *b)
{
	if (args->swap)
		args->swap(a, b);
	else
		ft_memswap(a, b, args->size);
}

static inline void	_case_pair(t__sort *args)
{
	void	*obj[2];

	obj[0] = args->base;
	obj[1] = (char *)args->base + args->size;
	if (args->nmemb == 2 && args->less(obj[1], obj[0], args->args))
		_swap(args, obj[0], obj[1]);
}

static inline size_t	_partition(t__sort *args)
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
		if (!args->less(pivot, current, args->args))
			_swap(args, current, (char *)args->base + args->size * i++);
		j++;
	}
	_swap(args, (char *)args->base + args->size * i, pivot);
	return (i);
}

void	*ft__sort(t__sort *args)
{
	size_t	pi;

	if (args->nmemb == 0)
		;
	else if (args->nmemb < 3)
		_case_pair(args);
	else
	{
		pi = _partition(args);
		ft__sort(&(t__sort){args->base, pi, args->size,
			args->less, args->swap, args->args});
		ft__sort(&(t__sort){(char *)args->base + (pi + 1) * args->size,
			args->nmemb - (pi + 1), args->size,
			args->less, args->swap, args->args});
	}
	return (args->base);
}
