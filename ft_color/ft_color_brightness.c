/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_brightness.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:37:33 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/13 17:39:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>

t_color	ft_color_brightness(double brightness, t_color color)
{
	const t_color	tmp = {._ = {
		.alpha = color._.alpha,
		.red = color._.red * brightness,
		.green = color._.green * brightness,
		.blue = color._.blue * brightness
	}};

	return (tmp);
}
