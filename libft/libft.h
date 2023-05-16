/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:51:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/16 22:15:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int	ft_isalpha(char c);
int ft_isdigit(char c);
int ft_isalnum(char c);
int ft_isascii(char c);
int ft_isprint(char c);

int ft_strlen(char *s);

void *ft_memset(void *buf, int ch, int n);
void ft_bzero(void *s, int n);
void *ft_memcpy(void *dst, void *src, int n);

#endif
