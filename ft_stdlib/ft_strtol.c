/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:15:45 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/22 03:50:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ft_ctype.h>
#include <stddef.h>

static int	pre(const char **nptr, int *base, int *neg);
static int	internal(const char **nptr, int neg, int base, unsigned long *acc);
static int	tonbr(int c);

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
	if (**nptr == '+' || **nptr == '-')
		*neg = *(*nptr)++ == '-';
	if ((*base == 0 || *base == 16) && (*nptr)[0] == '0'
		&& ft_tolower((*nptr)[1]) == 'x')
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
		n = tonbr(**nptr);
		if (n < 0 || base <= n)
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

static int	tonbr(int c)
{
	c = ft_tolower(c);
	if (ft_isdigit(c))
		c -= '0';
	else if (ft_isalpha(c))
		c -= 'a' - 10;
	else
		c = -1;
	return (c);
}
