/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:24:34 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/10 16:20:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>

t_color	ft_color_mul(t_color a, t_color b)
{
	t_color	color;
	double	b_alpha;
	double	b_alpha_inversion;

	color.raw = 0;
	b_alpha = b._.alpha / 0xffp0;
	b_alpha_inversion = (0xff - b._.alpha) / 0xffp0;
	color._.alpha = b._.alpha * b_alpha + a._.alpha * b_alpha_inversion;
	color._.red = b._.red * b_alpha + a._.red * b_alpha_inversion;
	color._.green = b._.green * b_alpha + a._.green * b_alpha_inversion;
	color._.blue = b._.blue * b_alpha + a._.blue * b_alpha_inversion;
	return (color);
}
