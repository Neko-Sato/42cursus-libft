/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:28:31 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/14 22:27:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static inline unsigned long	_internal(
	char const *nptr, int neg, int *any)
{
	static const unsigned long	boundary[] = {
		LONG_MAX, -(unsigned long)LONG_MIN};
	const unsigned long			cutoff = boundary[neg] / 10;
	const unsigned int			cutlim = boundary[neg] % 10;
	unsigned long				acc;
	unsigned int				n;

	acc = 0;
	while (ft_isdigit(*nptr))
	{
		n = *nptr++ - '0';
		if (acc > cutoff || (acc == cutoff && n > cutlim))
		{
			*any = -1;
			return (0);
		}
		acc = acc * 10 + n;
	}
	return (acc);
}

int	ft_atoi(const char *nptr)
{
	static const long	boundary[] = {
		LONG_MAX, LONG_MIN};
	int					neg;
	unsigned long		acc;
	int					any;

	while (ft_isspace(*nptr))
		nptr++;
	neg = 0;
	if (*nptr == '-' || *nptr == '+')
		neg = *nptr++ == '-';
	any = 0;
	acc = _internal(nptr, neg, &any);
	if (any)
		return (boundary[neg]);
	if (neg)
		acc = -acc;
	return (acc);
}
