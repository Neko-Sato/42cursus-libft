/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:02:17 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/29 00:00:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>
#include <ft_string.h>
#include <ft_utils.h>

static int			special(const char **nptr, double *result);
static const char	*mantissa(const char *nptr, double *result, int hex);
static const char	*exponent(const char *nptr, double *result, int hex);

double	ft_strtod(const char *nptr, char **endptr)
{
	double	result;
	int		hex;
	int		neg;

	result = 0.;
	while (ft_isspace(*nptr))
		nptr++;
	neg = 0;
	if (ft_strnchr("-+", *nptr, 2))
		if (*nptr++ == '-')
			neg = 1;
	if (!special(&nptr, &result))
	{
		hex = !ft_strncasecmp("0x", nptr, 2);
		if (hex)
			nptr += 2;
		nptr = mantissa(nptr, &result, hex);
		nptr = exponent(nptr, &result, hex);
	}
	if (neg)
		*(unsigned long long *)&result |= 1ull << 63;
	if (endptr)
		*endptr = (char *)nptr;
	return (result);
}

static const char	*mantissa(const char *nptr, double *result, int hex)
{
	double	fraction;
	int		c;

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
		fraction = 1.;
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

static const char	*exponent(const char *nptr, double *result, int hex)
{
	int	c;
	int	exp;
	int	neg;

	if ((!hex && !ft_strncasecmp("e", nptr, 1)) || (hex && !ft_strncasecmp("p",
				nptr, 1)))
	{
		nptr++;
		exp = 0;
		neg = 0;
		if (ft_strnchr("-+", *nptr, 2))
			if (*nptr++ == '-')
				neg = 1;
		while (1)
		{
			c = ft_ctoi(*nptr, 10);
			if (c < 0)
				break ;
			exp = exp * 10 + c;
			nptr++;
		}
		while (exp--)
			*result *= (double []){10., .1, 2., .5}[hex << 1 | neg];
	}
	return (nptr);
}

static int	special(const char **nptr, double *result)
{
	if (!ft_strncasecmp("infinity", *nptr, 8))
	{
		*result = 1. / 0.;
		*nptr += 8;
	}
	else if (!ft_strncasecmp("inf", *nptr, 3))
	{
		*result = 1. / 0.;
		*nptr += 3;
	}
	else if (!ft_strncasecmp("nan", *nptr, 3))
	{
		*result = 0. / 0.;
		*nptr += 3;
		if (**nptr == '(' && ft_strchr(*nptr, ')'))
			*nptr = ft_strchr(*nptr, ')');
	}
	else
		return (0);
	return (1);
}
