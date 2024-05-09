/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:25:10 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/09 19:40:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_rgba(int r, int g, int b, int a)
{
	int	color;

	color = 0;
	color |= (a & 0xFF) << 24;
	color |= (r & 0xFF) << 16;
	color |= (g & 0xFF) << 8;
	color |= (b & 0xFF);
	return (color);
}
