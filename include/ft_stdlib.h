/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/26 12:53:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

unsigned int	ft_abs(int n);
double			ft_atof(const char *str);
long			ft_strtol(const char *nptr, char **endptr, int base);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			*ft_realloc(void *ptr, size_t size);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);

#endif
