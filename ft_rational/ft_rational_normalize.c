/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rational_normalize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:12:40 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 01:50:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rational/ft_rational.h>
#include <ft_stdlib/ft_stdlib.h>

static inline long	_gcd(long a, long b)
{
	long	tmp;

	while (b)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

void	ft_rational_normalize(t_rational *n)
{
	long	gcd;

	if (n->den == 0)
		return ;
	if (n->den < 0)
	{
		n->den = -n->den;
		n->num = -n->num;
	}
	gcd = _gcd(labs(n->num), n->den);
	n->num /= gcd;
	n->den /= gcd;
}
