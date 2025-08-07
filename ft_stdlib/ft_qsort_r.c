/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 04:56:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>
#include <ft_string/ft_string.h>

static void	case_pair(t_qsort_r *args)
{
	void	*obj[2];

	obj[0] = args->base;
	obj[1] = (char *)args->base + args->size;
	if (args->nmemb == 2 && args->compar(obj[0], obj[1], args->arg) > 0)
		ft_memswap(obj[0], obj[1], args->size);
}

static size_t	partition(t_qsort_r *args)
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
		if (args->compar(current, pivot, args->arg) <= 0)
			ft_memswap(current, (char *)args->base + args->size * i++,
				args->size);
		j++;
	}
	ft_memswap((char *)args->base + args->size * i, pivot, args->size);
	return (i);
}

void	ft_qsort_r(t_qsort_r *args)
{
	size_t	pi;

	if (args->nmemb == 0)
		return ;
	if (args->nmemb < 3)
		case_pair(args);
	else
	{
		pi = partition(args);
		ft_qsort_r(&(t_qsort_r){args->base, pi, args->size, args->compar,
			args->arg});
		ft_qsort_r(&(t_qsort_r){(char *)args->base + (pi + 1) * args->size,
			args->nmemb - (pi + 1), args->size, args->compar, args->arg});
	}
}
