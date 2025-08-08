/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:06 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/09 07:22:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_stdlib/ft_stdlib.h>
#include <ft_string/ft_string.h>
#include <ft_utils/ft_utils.h>
#include <math.h>

static inline int	__special(const char **nptr, long double *acc, int *any)
{
	static const char			*specials[] = {"infinity", "inf", "nan"};
	static const int			specials_len[] = {8, 3, 3};
	static const long double	specials_val[] = {INFINITY, INFINITY, NAN};
	size_t						i;
	const char					*tmp;

	i = 0;
	while (i < sizeof(specials) / sizeof(specials[0]))
	{
		if (!ft_strncasecmp(specials[i], *nptr, specials_len[i]))
		{
			*acc = specials_val[i];
			*nptr += specials_len[i];
			if (i == 2 && **nptr == '(')
			{
				tmp = ft_strchr(*nptr + 1, ')');
				if (tmp)
					*nptr = tmp + 1;
			}
			*any = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

static inline void	__integer(const char **nptr, long double *acc,
	int *base, int *any)
{
	int	n;

	*base = 10;
	if (!ft_strncasecmp(*nptr, "0x", 2))
	{
		*nptr += 2;
		*base = 16;
	}
	while (1)
	{
		n = ft_digitval(**nptr);
		if (n == -1 || n >= *base)
			break ;
		*any = 1;
		*acc = *acc * *base + n;
		(*nptr)++;
	}
}

static inline void	__fraction(const char **nptr, long double *acc,
	int base, int *any)
{
	int				n;
	long double		fraction;

	if (**nptr != '.')
		return ;
	(*nptr)++;
	fraction = 1.l;
	while (1)
	{
		n = ft_digitval(**nptr);
		if (n == -1 || n >= base)
			break ;
		*any = 1;
		fraction /= base;
		*acc += n * fraction;
		(*nptr)++;
	}
}

static inline void	__exponent(const char **nptr, long double *acc,
	int base, int any)
{
	long						exp;
	int							neg;
	unsigned long				count;

	if (any && ft_tolower(**nptr) != "ep"[base == 16])
		return ;
	(*nptr)++;
	exp = ft_strtol(*nptr, (char **)nptr, 10);
	neg = exp < 0;
	count = ft_labs(exp);
	while (count--)
	{
		if (neg)
			*acc /= base;
		else
			*acc *= base;
	}
}

long double	ft_strtold(const char *nptr, char **endptr)
{
	long double	acc;
	const char	*s;
	int			neg;
	int			any;
	int			base;

	acc = 0;
	nptr = ft_skip_whitespace(nptr);
	s = nptr;
	neg = 0;
	if (*nptr == '-' || *nptr == '+')
		neg = *nptr++ == '-';
	any = 0;
	if (!__special(&nptr, &acc, &any))
	{
		__integer(&nptr, &acc, &base, &any);
		__fraction(&nptr, &acc, base, &any);
		__exponent(&nptr, &acc, base, any);
	}
	if (neg)
		acc = -acc;
	if (endptr)
		*endptr = (char *)(const char *[]){nptr, s}[!any];
	return (acc);
}
