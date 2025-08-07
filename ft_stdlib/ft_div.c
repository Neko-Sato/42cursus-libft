/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 21:21:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 21:22:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

div_t	ft_div(int numer, int denom)
{
	div_t   result;

	result.quot = numer / denom;
	result.rem = numer % denom;
	return (result);
}
