/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 04:31:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>

static int	wrapper_cmp(const void *v1, const void *v2, void *cmp)
{
	return ((int (*)(const void *, const void *))cmp)(v1, v2);
}

void	ft_qsort(t_qsort *args)
{
	ft_qsort_r(&(t_qsort_r){
		.base = args->base,
		.nmemb = args->nmemb,
		.size = args->size,
		.compar = wrapper_cmp,
		.arg = (void *)args->compar,
	});
}
