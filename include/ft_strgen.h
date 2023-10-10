/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgen.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:30:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 22:37:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRGEN_H
# define FT_STRGEN_H

# include <stddef.h>

# define STRGEN_BUFFSIZE 20

typedef struct s_strgen
{
	char	*str;
	char	buff[STRGEN_BUFFSIZE];
	size_t	position;
	int		error;
}			t_strgen;

t_strgen	*ft_strgennew(void);
void		ft_strgendel(t_strgen *strgen);
void		ft_strgenclearbuff(t_strgen *strgen);
void		ft_strgenchr(t_strgen *strgen, char insert);
void		ft_strgenstr(t_strgen *strgen, char *insert);
char		*ft_strgencomp(t_strgen *strgen);
char		*ft_strgenfetch(t_strgen *strgen, size_t len);

#endif
