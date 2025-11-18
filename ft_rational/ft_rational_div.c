/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rational_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:50:31 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 04:05:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rational/ft_rational.h>

t_rational	ft_rational_div(t_rational a, t_rational b)
{
	t_rational	tmp;

	tmp.num = a.num * b.den;
	tmp.den = a.den * b.num;
	ft_rational_normalize(&tmp);
	return (tmp);
}
