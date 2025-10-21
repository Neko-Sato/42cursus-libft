/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 04:59:40 by hshimizu          #+#    #+#             */
/*   Updated: 2025/10/21 21:23:57 by hshimizu         ###   ########.fr       */
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

void				*ft_reverse(void *base, size_t nmemb, size_t size);

extern const char	*g_ascii_lowercase;
extern const char	*g_ascii_uppercase;
extern const char	*g_ascii_letter;
extern const char	*g_digits;
extern const char	*g_ascii_alunum;
extern const char	*g_whitespace;

#endif
