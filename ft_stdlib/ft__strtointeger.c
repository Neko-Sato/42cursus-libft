/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strtointeger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:30:55 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/05 09:11:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_string/ft_string.h>
#include <ft_utils/ft_utils.h>
#include <limits.h>

static inline int	_check_base(unsigned int base, const char *nptr,
		char **endptr)
{
	if (base != 0 && (base < 2 || base > 36))
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (1);
	}
	return (0);
}

static inline unsigned int	_prefix(const char **nptr, unsigned int base)
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

static inline unsigned long long	_convert(const char **nptr,
		unsigned int base, int *any)
{
	const unsigned long long	cutoff = ULLONG_MAX / base;
	const unsigned int			cutlim = ULLONG_MAX % base;
	unsigned long long			acc;
	int							n;

	*any = 0;
	acc = 0;
	while (**nptr)
	{
		n = ft_digitval(**nptr);
		if (n == -1 || base <= (unsigned int)n)
			break ;
		if (*any < 0 || cutoff < acc || (cutoff == acc
				&& cutlim < (unsigned int)n))
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

static inline unsigned long long	_finally(unsigned long long acc, int neg,
		unsigned long long lim)
{
	if (acc >= lim)
	{
		if (!(lim & 1) && !neg)
			return (lim - 1);
		else if (acc > lim)
			return (lim);
	}
	return ((acc ^ -neg) + neg);
}

unsigned long long	ft__strtointeger(const char *nptr, char **endptr,
		unsigned int base, unsigned long long lim)
{
	const char			*s;
	int					neg;
	int					any;
	unsigned long long	acc;

	if (_check_base(base, nptr, endptr))
		return (0);
	s = nptr;
	nptr = ft_skip_whitespace(nptr);
	neg = 0;
	if (*nptr == '-' || *nptr == '+')
		neg = *nptr++ == '-';
	base = _prefix(&nptr, base);
	acc = _convert(&nptr, base, &any);
	if (any == -1)
	{
		acc = lim;
		neg &= ~(lim & 1);
	}
	if (endptr)
		*endptr = (char *)(const char *[]){nptr, s}[!any];
	return (_finally(acc, neg, lim));
}
