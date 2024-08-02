/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:02:17 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/16 01:29:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>
#include <ft_stdlib.h>
#include <ft_string.h>
#include <ft_utils.h>
#include <math.h>

static void			internal(const char **nptr, long double *result);
static int			special(const char **nptr, long double *result);
static const char	*mantissa(const char *nptr, long double *result, int hex);
static const char	*exponent(const char *nptr, long double *result, int hex);

//	this function may produce results different from the original
long double	ft_strtold(const char *nptr, char **endptr)
{
	long double	result;
	int			neg;
	const char	*save;

	result = 0.l;
	save = nptr;
	while (ft_isspace(*nptr))
		nptr++;
	neg = 0;
	if (ft_strnchr("-+", *nptr, 2))
		if (*nptr++ == '-')
			neg = 1;
	if (ft_isdigit(*nptr))
		internal(&nptr, &result);
	else
		nptr = save;
	if (neg)
		result = -result;
	if (endptr)
		*endptr = (char *)nptr;
	return (result);
}

static void	internal(const char **nptr, long double *result)
{
	int	hex;

	if (special(nptr, result))
		return ;
	hex = !ft_strncasecmp("0x", *nptr, 2);
	if (hex)
		nptr += 2;
	*nptr = mantissa(*nptr, result, hex);
	*nptr = exponent(*nptr, result, hex);
}

static const char	*mantissa(const char *nptr, long double *result, int hex)
{
	long double	fraction;
	int			c;

	while (1)
	{
		c = ft_ctoi(*nptr, (int []){10, 16}[hex]);
		if (c < 0)
			break ;
		*result = *result * (int []){10, 16}[hex] + c;
		nptr++;
	}
	if (*nptr == '.')
	{
		fraction = 1.l;
		while (1)
		{
			nptr++;
			c = ft_ctoi(*nptr, (int []){10, 16}[hex]);
			if (c < 0)
				break ;
			fraction /= (int []){10, 16}[hex];
			*result += c * fraction;
		}
	}
	return (nptr);
}

static const char	*exponent(const char *nptr, long double *result, int hex)
{
	long			exp;
	int				neg;
	unsigned long	count;

	if (ft_tolower(*nptr) == "ep"[hex])
	{
		nptr++;
		exp = ft_strtol(nptr, (char **)&nptr, 10);
		neg = exp < 0;
		if (neg)
			count = -exp;
		else
			count = exp;
		while (count--)
			*result *= (long double []){10.l, .1l, 2.l, .5l}[hex << 1 | neg];
	}
	return (nptr);
}

static int	special(const char **nptr, long double *result)
{
	if (!ft_strncasecmp("infinity", *nptr, 8))
	{
		*result = INFINITY;
		*nptr += 8;
	}
	else if (!ft_strncasecmp("inf", *nptr, 3))
	{
		*result = INFINITY;
		*nptr += 3;
	}
	else if (!ft_strncasecmp("nan", *nptr, 3))
	{
		*result = NAN;
		*nptr += 3;
		if (**nptr == '(' && ft_strchr(*nptr, ')'))
			*nptr = ft_strchr(*nptr, ')');
	}
	else
		return (0);
	return (1);
}
