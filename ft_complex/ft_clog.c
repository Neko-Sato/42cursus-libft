/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:29:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:20:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	ft_clog(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){log(a.real) / log(b.real), 0});
	return (ft_cdiv(ft_cln(a), ft_cln(b)));
}
