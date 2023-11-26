/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:15:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/26 13:54:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <ft_ctype.h>

static int	tonbr(int c);
static long	core(const char *nptr, int neg, char **endptr, int base);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int	neg;

	neg = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		neg = *nptr++ == '-';
	if ((base == 0 || base == 16) && nptr[0] == '0'
		&& ft_tolower(nptr[1]) == 'x')
	{
		base = 16;
		nptr += 2;
	}
	if (!base)
		base = (int []){10, 8}[*nptr++ == '0'];
	return (core(nptr, neg, endptr, base));
}

static long	core(const char *nptr, int neg, char **endptr, int base)
{
	unsigned long	acc;
	unsigned long	cutoff;
	int				n;

	cutoff = (~0ul >> 1) ^ -neg;
	acc = 0;
	while (1)
	{
		n = tonbr(*nptr);
		if (n < 0 || base <= n)
			break ;
		if (cutoff - acc < (unsigned long)n)
		{
			acc = cutoff;
			errno = EINVAL;
			break ;
		}
		acc = acc * base + n;
		nptr++;
	}
	if (neg)
		acc *= -1;
	if (endptr)
		*endptr = (char *)nptr;
	return (acc);
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
