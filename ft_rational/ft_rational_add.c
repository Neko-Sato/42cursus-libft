/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rational_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:56:18 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 01:52:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_rational/ft_rational.h>

void	ft_rational_add(const t_rational *a, const t_rational *b,
		t_rational *res)
{
	t_rational	tmp;

	tmp.num = a->num * b->den + b->num * a->den;
	tmp.den = a->den * b->den;
	ft_rational_normalize(&tmp);
	*res = tmp;
}
