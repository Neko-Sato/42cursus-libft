/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interval.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:19:04 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/14 01:36:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTERVAL_H
# define FT_INTERVAL_H

typedef enum e_interval
{
	I_CC,
	I_OO,
	I_OC,
	I_CO
}	t_interval;

int	ft_interval(long a, long b, long c, t_interval type);
int	ft_intervalf(double a, double b, double c, t_interval type);

#endif
