/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/10 14:19:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>
#include <ft_utils.h>

t_color	ft_color_add(t_color a, t_color b)
{
	t_color	color;

	color.raw = 0;
	color._.alpha = ft_min(a._.alpha + b._.alpha, 0xFF);
	color._.red = ft_min(a._.red + b._.red, 0xFF);
	color._.green = ft_min(a._.green + b._.green, 0xFF);
	color._.blue = ft_min(a._.blue + b._.blue, 0xFF);
	return (color);
}
