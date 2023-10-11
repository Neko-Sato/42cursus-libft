/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:17:31 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:17:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	ft_cdiv(t_complex a, t_complex b)
{
	t_complex	ret;
	double		pow2_abs_b;

	ret = ft_cmul(a, ft_conj(b));
	pow2_abs_b = pow(b.real, 2) + pow(b.imag, 2);
	ret.real /= pow2_abs_b;
	ret.imag /= pow2_abs_b;
	return (ret);
}
