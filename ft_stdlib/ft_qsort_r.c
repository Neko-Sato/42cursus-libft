/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 17:01:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>
#include <ft_utils/ft_utils.h>

static int	_less(const void *a, const void *b, void *args)
{
	return (((t_qsort_r *)args)->compar(a, b, ((t_qsort_r *)args)->args) < 0);
}

void	ft_qsort_r(t_qsort_r *args)
{
	ft__sort(&(t__sort){
		.base = args->base,
		.nmemb = args->nmemb,
		.size = args->size,
		.less = _less,
		.swap = NULL,
		.args = args,
	});
}
