/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:24:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/23 22:14:12 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SLIST_H
# define FT_SLIST_H

# include <stddef.h>

typedef struct s_slist_node
{
	struct s_slist_node	*_next;
	char				data[];
}						t_slist_node;

t_slist_node			*ft_slist_node_new(size_t size);
void					ft_slist_node_delete(t_slist_node *node);
t_slist_node			*ft_slist_node_next(t_slist_node *node);

typedef struct s_slist
{
	t_slist_node		*_head;
	size_t				_size;
}						t_slist;

int						ft_slist_init(t_slist *slist);
void					ft_slist_destroy(t_slist *slist);
void					ft_slist_move(t_slist *dst, t_slist *src);

size_t					ft_slist_size(t_slist *slist);
t_slist_node			*ft_slist_head(t_slist *slist);
void					ft_slist_insert(t_slist *slist, t_slist_node *pos,
							t_slist_node *node);
t_slist_node			*ft_slist_extract(t_slist *slist, t_slist_node *pos);

#endif
