/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:21:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 21:23:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

ldiv_t	ft_ldiv(long numer, long denom)
{
	ldiv_t	result;

	result.quot = numer / denom;
	result.rem = numer % denom;
	return (result);
}
