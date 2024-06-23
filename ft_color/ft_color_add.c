/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/06/23 22:33:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <ft_utils.h>

t_color	ft_color_add(t_color a, t_color b)
{
	t_color			color;
	const double	a_alpha = a._.alpha / 0xffp0;
	const double	b_alpha = b._.alpha / 0xffp0;

	color.raw = 0;
	color._.alpha = 0xff * (a_alpha + b_alpha - a_alpha * b_alpha);
	color._.red = ft_min(0xff, a._.red * a_alpha + b._.red * b_alpha);
	color._.green = ft_min(0xff, a._.green * a_alpha + b._.green * b_alpha);
	color._.blue = ft_min(0xff, a._.blue * a_alpha + b._.blue * b_alpha);
	return (color);
}
