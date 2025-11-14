/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 04:59:40 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 05:02:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

int					ft_starts_with(char *str, char *prefix);
int					ft_ends_with(char *str, char *suffix);

int					ft_intcmp(const int *ptr1, const int *ptr2);
int					ft_strptrcmp(const char **ptr1, const char **ptr2);

int					ft_digitval(int c);
char				*ft_skip_whitespace(const char *str);

typedef struct s_reverse
{
	void			*base;
	size_t			nmemb;
	size_t			size;
	void			(*swap)(void *, void *);
}					t_reverse;

void				*ft_reverse(t_reverse *args);

typedef struct s__sort
{
	void			*base;
	size_t			nmemb;
	size_t			size;
	int				(*less)(const void *, const void *, void *args);
	void			(*swap)(void *, void *);
	void			*args;
}					t__sort;

void				*ft__sort(t__sort *args);

typedef struct s_sort
{
	void			*base;
	size_t			nmemb;
	size_t			size;
	int				(*less)(const void *, const void *);
	void			(*swap)(void *, void *);
}					t_sort;

void				*ft_sort(t_sort *args);

extern const char	*g_ascii_lowercase;
extern const char	*g_ascii_uppercase;
extern const char	*g_ascii_letter;
extern const char	*g_digits;
extern const char	*g_ascii_alnum;
extern const char	*g_whitespace;

#endif
