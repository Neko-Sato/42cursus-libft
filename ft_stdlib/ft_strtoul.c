/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:29:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 15:33:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_string/ft_string.h>
#include <limits.h>

static inline int	digitval(int c)
{
	static const char	digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	static const size_t	digits_len = sizeof(digits) - 1;
	const char			*match;

	match = ft_memchr(digits, ft_tolower(c), digits_len);
	if (!match)
		return (-1);
	return (match - digits);
}

static inline void	__pre(const char **nptr, int *base, int *neg)
{
	while (ft_isspace(*(*nptr)))
		(*nptr)++;
	*neg = 0;
	if (*(*nptr) == '-' || *(*nptr) == '+')
		*neg = *(*nptr)++ == '-';
	if ((*base == 0 || *base == 16) && ((*nptr)[0] == '0'
		&& ft_tolower((*nptr)[1]) == 'x'))
	{
		(*nptr) += 2;
		*base = 16;
	}
	else if (*base == 0)
	{
		*base = (int []){8, 10}[(*nptr)[0] != '0'];
		(*nptr)++;
	}
}

static inline void	__set_cutoff_cutlim(unsigned long *cutoff,
		unsigned int *cutlim, int base, int neg)
{
	(void)neg;
	*cutoff = ULONG_MAX;
	*cutlim = *cutoff % base;
	*cutoff /= base;
}

static inline unsigned long	__internal(const char **nptr, int base, int neg,
		int *any)
{
	unsigned long	acc;
	int				n;
	unsigned long	cutoff;
	unsigned int	cutlim;

	__set_cutoff_cutlim(&cutoff, &cutlim, base, neg);
	acc = 0;
	while (*(*nptr))
	{
		n = digitval(*(*nptr));
		if (n == -1 || n >= base)
			break ;
		if (*any < 0 || cutoff < acc || (acc == cutoff
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

unsigned long	ft_strtoul(const char *nptr, char **endptr, int base)
{
	unsigned long	acc;
	int				neg;
	int				any;
	const char		*s;

	if (base != 0 && (base < 2 || base > 36))
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	__pre(&nptr, &base, &neg);
	any = 0;
	s = nptr;
	acc = __internal(&nptr, base, neg, &any);
	if (any == -1)
		acc = ULONG_MAX;
	else if (neg)
		acc = -acc;
	if (endptr)
		*endptr = (char *)(const char *[]){nptr, s}[!any];
	return (acc);
}
