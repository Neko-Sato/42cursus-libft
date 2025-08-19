/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:24:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/16 18:41:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stddef.h>

# define FT_VECTOR_GROWTH_FACTOR 2

typedef struct s_vector
{
	char	*_data;
	size_t	_elemsize;
	size_t	_size;
	size_t	_capa;
}			t_vector;

int			ft_vector_init(t_vector *vector, size_t elemsize);
void		ft_vector_destroy(t_vector *vector);

void		*ft_vector_data(t_vector *vector);
size_t		ft_vector_size(t_vector *vector);
int			ft_vector_resize(t_vector *vector, size_t n);

#endif
