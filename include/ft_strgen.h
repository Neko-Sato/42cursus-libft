/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/16 12:51:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRGEN_H
# define FT_STRGEN_H

# include <stddef.h>

typedef struct s_strgen
{
	char	*str;
	size_t	position;
	int		error;
	char	buff[0];
}			t_strgen;

t_strgen	*ft_strgennew(size_t buffsize);
void		ft_strgendel(t_strgen *strgen);
void		ft_strgenflush(t_strgen *strgen);
void		ft_strgenchr(t_strgen *strgen, char insert);
void		ft_strgenstr(t_strgen *strgen, char *insert);
char		*ft_strgencomp(t_strgen *strgen);
char		*ft_strgenfetch(t_strgen *strgen, size_t len);

#endif
