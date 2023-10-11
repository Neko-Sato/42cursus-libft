/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cexp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:18:41 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:18:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	ft_cexp(t_complex c)
{
	t_complex	ret;

	ret.real = exp(c.real) * cos(c.imag);
	ret.imag = exp(c.real) * sin(c.imag);
	return (ret);
}
