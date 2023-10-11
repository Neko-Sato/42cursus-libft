/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cln.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:19:17 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 15:19:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_complex.h>
#include <math.h>

t_complex	ft_cln(t_complex c)
{
	t_complex	ret;

	ret.real = log(sqrt(pow(c.real, 2) + pow(c.imag, 2)));
	ret.imag = ft_carg(c);
	return (ret);
}
