/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:16:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:16:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>

t_complex	ft_csub(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real - b.real;
	ret.imag = a.imag - b.imag;
	return (ret);
}
