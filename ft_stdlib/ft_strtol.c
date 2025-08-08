/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:29:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/09 07:14:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_string/ft_string.h>
#include <ft_utils/ft_utils.h>
#include <limits.h>

static inline int	__check_sign(const char **nptr)
{
	int	neg;

	neg = 0;
	if (**nptr == '-' || **nptr == '+')
		neg = *(*nptr)++ == '-';
	return (neg);
}

static inline int	__check_base(const char **nptr, int base)
{
	if ((base == 0 || base == 16) && !ft_strncasecmp(*nptr, "0x", 2))
	{
		*nptr += 2;
		base = 16;
	}
	else if ((base == 0 || base == 8) && **nptr == '0')
	{
		(*nptr)++;
		base = 8;
	}
	else if (base == 0)
		base = 10;
	return (base);
}

static inline int	__convert(const char **nptr, int base,
		unsigned long *acc, int neg)
{
	int				any;
	int				n;
	unsigned long	cutoff;
	unsigned int	cutlim;

	any = 0;
	cutoff = (unsigned long []){LONG_MAX, -(unsigned long)LONG_MIN}[neg];
	cutlim = cutoff % base;
	cutoff /= base;
	while (**nptr)
	{
		n = ft_digitval(**nptr);
		if (n == -1 || n >= base)
			break ;
		if (any < 0 || cutoff < *acc
			|| (*acc == cutoff && cutlim < (unsigned int)n))
			any = -1;
		else
		{
			any = 1;
			*acc = *acc * base + n;
		}
		(*nptr)++;
	}
	return (any);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	const char		*s;
	int				neg;
	int				any;
	unsigned long	acc;

	if (base != 0 && (base < 2 || base > 36))
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	nptr = ft_skip_whitespace(nptr);
	s = nptr;
	neg = __check_sign(&nptr);
	base = __check_base(&nptr, base);
	acc = 0;
	any = __convert(&nptr, base, &acc, neg);
	if (any == -1)
		acc = (long []){LONG_MAX, LONG_MIN}[neg];
	else if (neg)
		acc = -acc;
	if (endptr)
		*endptr = (char *)(const char *[]){nptr, s}[!any];
	return (acc);
}
