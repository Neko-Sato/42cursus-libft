/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:29:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/30 21:08:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>
#include <limits.h>

unsigned long long	ft_strtoull(const char *nptr, char **endptr, int base)
{
	return (ft__strtointeger(nptr, endptr, base, ULLONG_MAX));
}
