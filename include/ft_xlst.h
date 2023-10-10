/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 23:27:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XLST_H
# define FT_XLST_H

# include <stddef.h>

size_t	ft_xlstlen(void *lst, size_t size);
int		ft_xlstat(void *lst, size_t size, int index, void *dst);
int		ft_xlstset(void *lst, size_t size, int index, void *src);
int		ft_xlstappend(void *lst_ptr, size_t size, void *new);
int		ft_xlstinsert(void *lst_ptr, size_t size, void *new, int index);
int		ft_xlstpop(void *lst_ptr, size_t size, int index, void *dst);
void	ft_xlstclear(void *lst_ptr, size_t size);
void	*ft_xlst2array(void *lst, size_t size, size_t *__len);

#endif
