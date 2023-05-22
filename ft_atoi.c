/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:06:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/21 15:44:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static long	ft_atol(const char *str)
{
	unsigned long	cutoff;
	int				neg;
	int				n;
	unsigned long	result;

	neg = 0;
	result = 0;
	while ((0x08 < *str && *str < 0x0e) || *str == 0x20)
		str++;
	if (*str == '+' || *str == '-')
		neg = *str++ == '-';
	cutoff = neg * (unsigned long)LONG_MIN + !neg * (unsigned long)LONG_MAX;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		n = *str++ - '0';
		if (result >= cutoff || cutoff - result < (unsigned long)n)
		{
			result = cutoff;
			break ;
		}
		result += n;
	}
	return ((1 + (-2 * neg)) * result);
}

int	ft_atoi(const char *str)
{
	return ((int)ft_atol(str));
}
