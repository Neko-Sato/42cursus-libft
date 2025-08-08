/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:44:06 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 15:48:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>
#include <ft_string/ft_string.h>
#include <limits.h>
#include <math.h>

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

long double	ft_strtold(const char *nptr, char **endptr)
{
	(void)digitval;
	(void)nptr;
	(void)endptr;
	return (.0l);
}
