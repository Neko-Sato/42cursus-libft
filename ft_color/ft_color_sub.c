/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/10 14:19:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <ft_utils.h>

t_color	ft_color_sub(t_color a, t_color b)
{
	t_color	color;

	color.raw = 0;
	color._.alpha = ft_max(a._.alpha - b._.alpha, 0);
	color._.red = ft_max(a._.red - b._.red, 0);
	color._.green = ft_max(a._.green - b._.green, 0);
	color._.blue = ft_max(a._.blue - b._.blue, 0);
	return (color);
}
