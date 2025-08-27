/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:09:43 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/26 02:51:33 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>

void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);

int					ft_abs(int n);
long				ft_labs(long n);
long long			ft_llabs(long long n);

div_t				ft_div(int numer, int denom);
ldiv_t				ft_ldiv(long numer, long denom);
lldiv_t				ft_lldiv(long long numer, long long denom);

long				ft_atol(const char *nptr);
long long			ft_atoll(const char *nptr);
double				ft_atof(const char *nptr);

long				ft_strtol(const char *nptr, char **endptr, int base);
long long			ft_strtoll(const char *nptr, char **endptr, int base);
unsigned long		ft_strtoul(const char *nptr, char **endptr, int base);
unsigned long long	ft_strtoull(const char *nptr, char **endptr, int base);
float				ft_strtof(const char *nptr, char **endptr);
double				ft_strtod(const char *nptr, char **endptr);
long double			ft_strtold(const char *nptr, char **endptr);

typedef struct s_bsearch
{
	const void		*key;
	const void		*base;
	size_t			n;
	size_t			size;
	int				(*cmp)(const void *, const void *);
}					t_bsearch;

void				*ft_bsearch(t_bsearch *args);

typedef struct s_qsort
{
	void			*base;
	size_t			nmemb;
	size_t			size;
	int				(*compar)(const void *, const void *);
}					t_qsort;

void				ft_qsort(t_qsort *args);

typedef struct s_qsort_r
{
	void			*base;
	size_t			nmemb;
	size_t			size;
	int				(*compar)(const void *, const void *, void *);
	void			*arg;
}					t_qsort_r;

void				ft_qsort_r(t_qsort_r *args);

#endif
