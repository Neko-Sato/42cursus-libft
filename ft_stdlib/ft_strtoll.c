/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:29:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/05 08:24:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdlib/ft_stdlib.h>
#include <limits.h>

long long	ft_strtoll(const char *nptr, char **endptr, int base)
{
	return (ft__strtointeger(nptr, endptr, base, LLONG_MIN));
}
