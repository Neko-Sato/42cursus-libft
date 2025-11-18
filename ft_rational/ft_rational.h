/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rational.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:38:41 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/19 01:47:38 by hshimizu         ###   ########.fr       */
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

void		ft_rational_add(const t_rational *a, const t_rational *b,
				t_rational *res);
void		ft_rational_sub(const t_rational *a, const t_rational *b,
				t_rational *res);
void		ft_rational_mul(const t_rational *a, const t_rational *b,
				t_rational *res);
void		ft_rational_div(const t_rational *a, const t_rational *b,
				t_rational *res);

#endif
