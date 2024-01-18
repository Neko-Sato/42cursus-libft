/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/01/18 19:44:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

int			ft_sign(int n);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
size_t		ft_digit(unsigned int n);
int			ft_isnumber(const char *src, int issigned);
int			ft_gcd(int a, int b);
int			ft_lcm(int a, int b);
int			ft_isprime(int n);
int			ft_intcmp(int a, int b);

#endif
