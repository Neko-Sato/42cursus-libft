/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:08:26 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/26 22:27:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TABLE_H
# define FT_TABLE_H

# include <stddef.h>

typedef struct s_table
{
	char	*key;
	void	*value;
	t_table	*left;
	t_table	*right;
}			t_table;

int			ft_dict_set(t_table **table, char *key, void *value);
void		*ft_dict_get(t_table **table, char *key, void *value);
void		ft_dict_del(t_table **table, char *key);
void		ft_dict_clear(t_table **table);

#endif