/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:46 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:19:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	ft_cpow(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){pow(a.real, b.real), 0});
	return (ft_cexp(ft_cmul(b, ft_cln(a))));
}
