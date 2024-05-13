/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intervalf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:24:50 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/14 01:39:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_interval.h>

int	ft_intervalf(double a, double b, double c, t_interval type)
{
	if (type == I_CC)
		return (a <= b && b <= c);
	else if (type == I_OO)
		return (a < b && b < c);
	else if (type == I_OC)
		return (a < b && b <= c);
	else if (type == I_CO)
		return (a <= b && b < c);
	return (0);
}
