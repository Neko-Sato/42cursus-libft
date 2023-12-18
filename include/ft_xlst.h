/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 10:08:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XLST_H
# define FT_XLST_H

# include <stddef.h>

typedef struct s_xlst
{
	struct s_xlst	*next;
	char			data[0];
}					t_xlst;

size_t				ft_xlstlen(t_xlst *lst);
void				*ft_xlstat(t_xlst *lst, int index);
int					ft_xlstset(t_xlst *lst, int index, void *src, size_t size);
int					ft_xlstget(t_xlst *lst, int index, void *dst, size_t size);
int					ft_xlstappend(t_xlst **lst_ptr, void *new, size_t size);
int					ft_xlstinsert(t_xlst **lst_ptr, int index, void *new,
						size_t size);
int					ft_xlstpop(t_xlst **lst_ptr, int index, void *dst,
						size_t size);
int					ft_xlstdel(t_xlst **lst_ptr, int index);
void				ft_xlstclear(t_xlst **lst_ptr);
void				*ft_xlst2array(t_xlst *lst, size_t size, size_t *__len);

#endif
