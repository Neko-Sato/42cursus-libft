/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 04:59:40 by hshimizu          #+#    #+#             */
/*   Updated: 2025/09/11 04:08:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

int					ft_startwith(char *str, char *prefix);
int					ft_endwith(char *str, char *suffix);

int					ft_intcmp(const int *ptr1, const int *ptr2);
int					ft_strptrcmp(const char **ptr1, const char **ptr2);

int					ft_digitval(int c);
char				*ft_skip_whitespace(const char *str);

void				*ft_reverse(void *base, size_t nmemb, size_t size);

extern const char	g_ascii_lowercase[27];
extern const char	g_ascii_uppercase[27];
extern const char	g_ascii_letter[53];
extern const char	g_digits[11];
extern const char	g_ascii_alunum[63];
extern const char	g_whitespace[7];

#endif
