/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:33:58 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/10 14:18:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# define COLOR_RAW_WHITE 0xFFFFFF
# define COLOR_RAW_BLACK 0x000000
# define COLOR_RAW_RED 0xFF0000
# define COLOR_RAW_GREEN 0x00FF00
# define COLOR_RAW_BLUE 0x0000FF
# define COLOR_RAW_YELLOW 0xFFFF00
# define COLOR_RAW_MAGENTA 0xFF00FF
# define COLOR_RAW_CYAN 0x00FFFF

typedef struct s_color_detail
{
	int alpha : 8;
	int red : 8;
	int green : 8;
	int blue : 8;
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
t_color				ft_color_mul(t_color a, t_color b);

#endif
