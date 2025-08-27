/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldiv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:21:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/26 02:51:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

lldiv_t	ft_lldiv(long long numer, long long denom)
{
	lldiv_t	result;

	result.quot = numer / denom;
	result.rem = numer % denom;
	return (result);
}
