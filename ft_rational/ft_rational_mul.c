/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rational_mul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:50:31 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 04:04:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rational/ft_rational.h>

t_rational	ft_rational_mul(t_rational a, t_rational b)
{
	t_rational	tmp;

	tmp.num = a.num * b.num;
	tmp.den = a.den * b.den;
	ft_rational_normalize(&tmp);
	return (tmp);
}
