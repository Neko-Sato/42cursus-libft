/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_inverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:07:38 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/24 21:21:10 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_color.h>

t_color	ft_color_inverse(t_color a)
{
	a._.red = 0xff - a._.red;
	a._.green = 0xff - a._.green;
	a._.blue = 0xff - a._.blue;
	return (a);
}
