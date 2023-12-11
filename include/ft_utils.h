/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/11 23:48:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

typedef struct s_switchcase_args
{
	size_t	(*get_case_num)(void *args);
	size_t	case_max;
	int		(**case_fns)(void *args);
	void	*args;
}			t_switchcase_args;

int			ft_sign(int n);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
size_t		ft_digit(unsigned int n);
int			ft_isnumber(const char *src, int issigned);
int			ft_gcd(int a, int b);
int			ft_lcm(int a, int b);
int			ft_isprime(int n);

#endif
