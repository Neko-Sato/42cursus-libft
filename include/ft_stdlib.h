/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/19 23:33:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

typedef int		(*t_compar_fn)(void *, void *);
typedef void	(*t_free_fn)(void *);

unsigned int	ft_abs(int n);
double			ft_atof(const char *str);
long			ft_strtol(const char *nptr, char **endptr, int base);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
void			ft_qsort(void *base, size_t nmemb, size_t size,
					t_compar_fn compar);
long			ft_random(void);
char			*ft_mktemp(char *template);
int				ft_mkstemp(char *template);
char			*ft_realpath(const char *path, char *resolved_path);

#endif
