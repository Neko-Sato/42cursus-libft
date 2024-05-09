/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsvt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:26:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/09 19:34:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <math.h>

unsigned int	ft_hsvt(double h, double s, double v, double t)
{
	unsigned int	ret;
	double			c;
	double			x;
	double			m;

	h = fmod(1 + fmod(h, 1), 1) * 6;
	c = s * v;
	x = c * (1 - fabs(fmod(h, 2) - 1));
	m = v - c;
	if (0. <= h && h < 1.)
		ret = ft_rgba((m + c) * 0xFF, (m + x) * 0xFF, m * 0xFF, t * 0xFF);
	else if (1. <= h && h < 2.)
		ret = ft_rgba((m + x) * 0xFF, (m + c) * 0xFF, m * 0xFF, t * 0xFF);
	else if (2. <= h && h < 3.)
		ret = ft_rgba(m * 0xFF, (m + c) * 0xFF, (m + x) * 0xFF, t * 0xFF);
	else if (3. <= h && h < 4.)
		ret = ft_rgba(m * 0xFF, (m + x) * 0xFF, (m + c) * 0xFF, t * 0xFF);
	else if (4. <= h && h < 5.)
		ret = ft_rgba((m + x) * 0xFF, m * 0xFF, (m + c) * 0xFF, t * 0xFF);
	else if (5. <= h && h < 6.)
		ret = ft_rgba((m + c) * 0xFF, m * 0xFF, (m + x) * 0xFF, t * 0xFF);
	else
		ret = ft_rgba(m * 0xFF, m * 0xFF, m * 0xFF, t * 0xFF);
	return (ret);
}
