/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_brightness.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:37:33 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/14 05:51:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <ft_utils.h>

t_color	ft_color_brightness(double brightness, t_color color)
{
	const t_color	tmp = {._ = {
		.alpha = color._.alpha,
		.red = ft_fmin(0xff, color._.red * brightness),
		.green = ft_fmin(0xff, color._.green * brightness),
		.blue = ft_fmin(0xff, color._.blue * brightness),
	}};

	return (tmp);
}
