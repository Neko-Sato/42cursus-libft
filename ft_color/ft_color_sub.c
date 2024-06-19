/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/06/19 22:34:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <ft_utils.h>

t_color	ft_color_sub(t_color a, t_color b)
{
	t_color	color;

	color.raw = 0;
	color._.alpha = a._.alpha * b._.alpha / 0xff;
	color._.red = a._.red * b._.red / 0xff;
	color._.green = a._.green * b._.green / 0xff;
	color._.blue = a._.blue * b._.blue / 0xff;
	return (color);
}
