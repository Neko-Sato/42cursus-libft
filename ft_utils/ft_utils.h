/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 04:59:40 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 05:15:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

int	ft_startwith(char *str, char *prefix);
int	ft_endwith(char *str, char *suffix);

int	ft_intcmp(const int *ptr1, const int *ptr2);
int	ft_strptrcmp(const char **ptr1, const char **ptr2);

#endif
