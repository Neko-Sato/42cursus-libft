/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:33:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/24 21:21:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# define COLOR_RAW_TRANSPARENT 0x00000000
# define COLOR_RAW_WHITE 0xFFFFFFFF
# define COLOR_RAW_BLACK 0xFF000000
# define COLOR_RAW_RED 0xFFFF0000
# define COLOR_RAW_GREEN 0xFF00FF00
# define COLOR_RAW_BLUE 0xFF0000FF
# define COLOR_RAW_YELLOW 0xFFFFFF00
# define COLOR_RAW_MAGENTA 0xFFFF00FF
# define COLOR_RAW_CYAN 0xFF00FFFF

typedef struct s_color_detail
{
	unsigned int	blue	: 8;
	unsigned int	green	: 8;
	unsigned int	red		: 8;
	unsigned int	alpha	: 8;
}					t_color_detail;

typedef union u_color
{
	unsigned int	raw;
	t_color_detail	_;
}					t_color;

t_color				ft_rgba(int r, int g, int b, int a);
t_color				ft_hsvt(double h, double s, double v, double t);

t_color				ft_color_add(t_color a, t_color b);
t_color				ft_color_sub(t_color a, t_color b);

t_color				ft_color_inverse(t_color a);
t_color				ft_color_brightness(double brightness, t_color color);

#endif
