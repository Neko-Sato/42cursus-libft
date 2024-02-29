/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:27:25 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/29 21:00:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib.h>
#include <ft_string.h>
#include <stddef.h>

static size_t	partition(void *base, size_t nmemb, size_t size,
					t_compar_fn compar);
static void		case_pair(void *base, size_t nmemb, size_t size,
					t_compar_fn compar);

void	ft_qsort(void *base, size_t nmemb, size_t size, t_compar_fn compar)
{
	size_t	pi;

	if (!nmemb)
		return ;
	if (nmemb < 3)
		return (case_pair(base, nmemb, size, compar));
	pi = partition(base, nmemb, size, compar);
	ft_qsort(base, pi, size, compar);
	base = (char *)base + (pi + 1) * size;
	ft_qsort(base, nmemb - (pi + 1), size, compar);
}

static void	case_pair(void *base, size_t nmemb, size_t size, t_compar_fn compar)
{
	void	*obj[2];

	obj[0] = (char *)base + 0 * size;
	obj[1] = (char *)base + 1 * size;
	if (nmemb == 2 && compar(obj[0], obj[1]) > 0)
		ft_memswap(obj[0], obj[1], size);
}

static size_t	partition(void *base, size_t nmemb, size_t size,
		t_compar_fn compar)
{
	void	*current;
	void	*pivot;
	size_t	i;
	size_t	j;

	pivot = (char *)base + size * (nmemb - 1);
	i = 0;
	j = 0;
	while (j < nmemb - 1)
	{
		current = (char *)base + size * j;
		if (compar(current, pivot) <= 0)
			ft_memswap(current, (char *)base + size * i++, size);
		j++;
	}
	ft_memswap((char *)base + size * i, pivot, size);
	return (i);
}
