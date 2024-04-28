/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:15:45 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/28 15:42:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ft_ctype.h>
#include <ft_string.h>
#include <ft_utils.h>
#include <stddef.h>

static int	pre(const char **nptr, int *base, int *neg);
static int	internal(const char **nptr, int neg, int base, unsigned long *acc);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int				neg;
	unsigned long	acc;

	if (pre(&nptr, &base, &neg))
	{
		errno = EINVAL;
		*endptr = NULL;
		return (0);
	}
	if (internal(&nptr, neg, base, &acc))
	{
		errno = EINVAL;
		acc = (~0ul >> 1) ^ -neg;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (acc);
}

static int	pre(const char **nptr, int *base, int *neg)
{
	*neg = 0;
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (ft_strnchr("+-", **nptr, 2))
		*neg = *(*nptr)++ == '-';
	if ((*base == 0 || *base == 16) && ft_strncasecmp("0x", *nptr, 2))
	{
		*base = 16;
		*nptr += 2;
	}
	if (!*base)
		*base = (int []){10, 8}[**nptr == '0'];
	return (*base < 2 || 36 < *base);
}

static int	internal(const char **nptr, int neg, int base, unsigned long *acc)
{
	int				overflow;
	unsigned long	cutoff;
	int				cutlim;
	int				n;

	overflow = 0;
	cutoff = (~0ul >> 1) ^ -neg;
	cutlim = cutoff % base;
	cutoff /= base;
	*acc = 0;
	while (**nptr)
	{
		n = ft_ctoi(**nptr, base);
		if (n < 0)
			break ;
		if (overflow || *acc > cutoff || (*acc == cutoff && n > cutlim))
			overflow = 1;
		else
			*acc = *acc * base + n;
		(*nptr)++;
	}
	if (!overflow && neg)
		*acc = -*acc;
	return (overflow);
}
