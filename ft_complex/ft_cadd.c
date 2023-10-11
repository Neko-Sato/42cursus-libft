/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:15:49 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:16:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>

t_complex	ft_cadd(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real + b.real;
	ret.imag = a.imag + b.imag;
	return (ret);
}
