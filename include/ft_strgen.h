/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/24 23:57:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRGEN_H
# define FT_STRGEN_H

# include <stddef.h>

# ifndef STRGEN_BUUFERSIZE
#  define STRGEN_BUUFERSIZE 20
# endif

typedef struct s_strgen
{
	char	*str;
	size_t	pos;
	size_t	size;
	char	buf[1];
}			t_strgen;

t_strgen	*ft_strgennew(size_t buffsize);
void		ft_strgendel(t_strgen *strgen);
int			ft_strgenflush(t_strgen *strgen);
int			ft_strgenchr(t_strgen *strgen, int c);
int			ft_strgenstr(t_strgen *strgen, char *s);
char		*ft_strgencomp(t_strgen *strgen);

#endif
