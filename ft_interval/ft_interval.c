/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:24:50 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/14 01:30:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_interval.h>

int	ft_interval(long a, long b, long c, t_interval type)
{
	if (type == I_CLOSED)
		return (a <= b && b <= c);
	else if (type == I_OPEN)
		return (a < b && b < c);
	else if (type == I_LOPEN_RCLOSED)
		return (a < b && b <= c);
	else if (type == I_LCLOSED_ROPEN)
		return (a <= b && b < c);
	return (0);
}
