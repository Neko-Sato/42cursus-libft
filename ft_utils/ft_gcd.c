/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:39:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 23:29:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_operator.h>

int	ft_gcd(int a, int b)
{
	int	temp;

	while (b)
	{
		temp = b;
		b = ft_mod(a, b);
		a = temp;
	}
	return (a);
}
