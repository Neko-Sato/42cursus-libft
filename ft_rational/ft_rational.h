/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rational.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:38:41 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 04:05:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RATIONAL_H
# define FT_RATIONAL_H

typedef struct s_rational
{
	long	num;
	long	den;
}			t_rational;

void		ft_rational_normalize(t_rational *n);

t_rational	ft_rational_add(t_rational a, t_rational b);
t_rational	ft_rational_sub(t_rational a, t_rational b);
t_rational	ft_rational_mul(t_rational a, t_rational b);
t_rational	ft_rational_div(t_rational a, t_rational b);

#endif
