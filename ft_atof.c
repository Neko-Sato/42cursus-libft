/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:48:59 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/29 17:43:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	decimal_portion(const char *str, double *result);
static size_t	exponent_portion(const char *str, double *result);
static int		str_is_nan(const char *str);
static int		str_is_inf(const char *str);

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	size_t	i;

	result = 0.;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] && ft_strchr("-+", str[i]))
		if (str[i++] == '-')
			sign = -1;
	if (str_is_nan(&str[i]))
		return ((0. * sign) / 0.);
	if (str_is_inf(&str[i]))
		return (sign / 0.);
	while (ft_isdigit(str[i]))
		result = result * 10. + (str[i++] - '0');
	i += decimal_portion(&str[i], &result);
	i += exponent_portion(&str[i], &result);
	return (result * sign);
}

static size_t	decimal_portion(const char *str, double *result)
{
	size_t	i;
	double	fraction;

	i = 0;
	fraction = 1.;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			fraction /= 10.;
			(*result) += (str[i++] - '0') * fraction;
		}
	}
	return (i);
}

static size_t	exponent_portion(const char *str, double *result)
{
	size_t	i;
	int		exponent;
	double	sign;

	i = 0;
	exponent = 0;
	sign = 10;
	if (str[i] && ft_strchr("eE", str[i]))
	{
		i++;
		if (str[i] && ft_strchr("-+", str[i]))
			if (str[i++] == '-')
				sign = .1;
		while (ft_isdigit(str[i]))
			exponent = exponent * 10 + (str[i++] - '0');
		while (exponent--)
			(*result) *= sign;
	}
	return (i);
}

static int	str_is_nan(const char *str)
{
	int		ret;
	size_t	i;

	ret = 1;
	i = 0;
	while (ret && i++ < 3)
		ret &= ft_tolower(str[0]) == "nan"[0];
	return (ret);
}

static int	str_is_inf(const char *str)
{
	int		ret;
	size_t	i;

	ret = 1;
	i = 0;
	while (ret && i++ < 3)
		ret &= ft_tolower(str[0]) == "inf"[0];
	return (ret);
}
