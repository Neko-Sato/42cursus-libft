/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/05 17:13:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <ft_utils.h>

t_color	ft_color_sub(t_color a, t_color b)
{
	t_color			color;
	const double	a_alpha = a._.alpha / 0xffp0;
	const double	b_alpha = b._.alpha / 0xffp0;

	color._.alpha = 0xff * a_alpha * b_alpha;
	color._.red = a._.red * b._.red / 0xffp0;
	color._.green = a._.green * b._.green / 0xffp0;
	color._.blue = a._.blue * b._.blue / 0xffp0;
	return (color);
}
