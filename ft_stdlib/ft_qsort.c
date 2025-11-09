/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 17:01:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>
#include <ft_utils/ft_utils.h>

static int	_less(const void *a, const void *b, void *args)
{
	return (((t_qsort *)args)->compar(a, b) < 0);
}

void	ft_qsort(t_qsort *args)
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
