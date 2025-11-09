/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 17:53:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_utils/ft_utils.h>

static int	_less(const void *a, const void *b, void *args)
{
	return (((t_sort *)args)->less(a, b));
}

void	*ft_sort(t_sort *args)
{
	return (ft__sort(&(t__sort){
			.base = args->base,
			.nmemb = args->nmemb,
			.size = args->size,
			.less = _less,
			.swap = args->swap,
			.args = args,
		}));
}
