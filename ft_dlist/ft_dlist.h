/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:24:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 09:04:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <stddef.h>

typedef struct s_dlist_node
{
	struct s_dlist_node	*_next;
	struct s_dlist_node	*_prev;
	char				data[];
}						t_dlist_node;

t_dlist_node			*ft_dlist_node_new(size_t size);
void					ft_dlist_node_delete(t_dlist_node *node);
t_dlist_node			*ft_dlist_node_next(t_dlist_node *node);
t_dlist_node			*ft_dlist_node_prev(t_dlist_node *node);

typedef struct s_dlist
{
	t_dlist_node		*_head;
	t_dlist_node		*_tail;
	size_t				_size;
}						t_dlist;

int						ft_dlist_init(t_dlist *dlist);
void					ft_dlist_destroy(t_dlist *dlist);

size_t					ft_dlist_size(t_dlist *dlist);
t_dlist_node			*ft_dlist_head(t_dlist *dlist);
t_dlist_node			*ft_dlist_tail(t_dlist *dlist);
t_dlist_node			*ft_dlist_end(t_dlist *dlist);
void					ft_dlist_insert(t_dlist *dlist, t_dlist_node *pos,
							t_dlist_node *node);
t_dlist_node			*ft_dlist_erase(t_dlist *dlist, t_dlist_node *pos);

#endif
