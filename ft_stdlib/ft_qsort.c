/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:30:11 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/03 13:14:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>
#include <ft_utils/ft_utils.h>

void	ft_qsort(t_qsort *args)
{
	ft_sort(&(t_sort){
		.base = args->base,
		.nmemb = args->nmemb,
		.size = args->size,
		.compar = args->compar,
		.swap = NULL,
	});
}
