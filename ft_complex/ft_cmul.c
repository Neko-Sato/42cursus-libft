/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:16:58 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:17:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>

t_complex	ft_cmul(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real * b.real - a.imag * b.imag;
	ret.imag = a.real * b.imag + a.imag * b.real;
	return (ret);
}
