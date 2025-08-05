/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:28:31 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 06:49:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_string/ft_string.h>
#include <limits.h>

static inline unsigned long	__internal2(
	const char **nptr, unsigned int base,
	int *any, unsigned long (*cutofflim)[2])
{
	static const char	digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	unsigned long		acc;
	const char			*c;
	unsigned int		n;

	acc = 0;
	while (**nptr)
	{
		c = ft_strchr(digits, ft_tolower(**nptr));
		if (!c)
			break ;
		n = c - digits;
		if (base <= n)
			break ;
		if (*any < 0 || (*cutofflim)[0] < acc
			|| (acc == (*cutofflim)[0] && (*cutofflim)[1] < n))
			*any = -1;
		else
		{
			*any = 1;
			acc = acc * base + n;
		}
		(*nptr)++;
	}
	return (acc);
}

static inline unsigned long	__internal1(
	const char *nptr, char **endptr, unsigned int base, int neg)
{
	unsigned long		acc;
	const char			*s;
	int					any;
	unsigned long		cutofflim[2];

	cutofflim[0] = (unsigned long []){LONG_MAX, -(unsigned long)LONG_MIN}[neg];
	cutofflim[1] = (unsigned long)(LONG_MAX % base);
	cutofflim[0] /= base;
	any = 0;
	s = nptr;
	acc = __internal2(&s, base, &any, &cutofflim);
	if (any == -1)
		acc = (long []){LONG_MAX, LONG_MIN}[neg];
	else if (neg)
		acc = -acc;
	if (endptr)
		*endptr = (char *)(const char *[]){s, nptr}[!any];
	return (acc);
}

static long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int	neg;

	if (base != 0 && (base < 2 || base > 36))
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	while (ft_isspace(*nptr))
		nptr++;
	neg = 0;
	if (*nptr == '-' || *nptr == '+')
		neg = *nptr++ == '-';
	if ((base == 0 || base == 16)
		&& (nptr[0] == '0' && ft_tolower(nptr[1]) == 'x'))
	{
		nptr += 2;
		base = 16;
	}
	else if (base == 0)
	{
		base = (int []){8, 10}[nptr[0] != '0'];
		nptr++;
	}
	return (__internal1(nptr, endptr, base, neg));
}

int	ft_atoi(const char *nptr)
{
	return ((int)ft_strtol(nptr, NULL, 10));
}
