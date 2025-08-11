/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:27:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 16:20:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stddef.h>

typedef enum e_btree_color
{
	FT_BTREE_COLOR_RED,
	FT_BTREE_COLOR_BLACK
}						t_btree_color;

typedef struct s_btree_node
{
	struct s_btree_node	*_parent;
	struct s_btree_node	*_left;
	struct s_btree_node	*_right;
	t_btree_color		_color;
	char				data[];
}						t_btree_node;

t_btree_node			*ft_btree_node_new(size_t size);
void					ft_btree_node_delete(t_btree_node *node);
t_btree_node			*ft_btree_node_next(t_btree_node *node);
t_btree_node			*ft_btree_node_prev(t_btree_node *node);

typedef struct s_btree
{
	t_btree_node		*_root;
	int					(*_compar)(const void *, const void *);
	size_t				_size;
}						t_btree;

int						ft_btree_init(t_btree *btree,
							int (*compar)(const void *, const void *));
void					ft_btree_destroy(t_btree *btree);

int						ft_btree_insert_unique(t_btree *btree,
							t_btree_node *node);
t_btree_node			*ft_btree_insert_replace(t_btree *btree,
							t_btree_node *node);
void					ft_btree_insert_multi(t_btree *btree,
							t_btree_node *node);
t_btree_node			*ft_btree_erase(t_btree *btree, t_btree_node *node);

t_btree_node			*ft_btree_head(t_btree *btree);
t_btree_node			*ft_btree_find(t_btree *btree, const void *data);
t_btree_node			*ft_btree_lower_bound(t_btree *btree, const void *data);
t_btree_node			*ft_btree_upper_bound(t_btree *btree, const void *data);
void					ft_btree_equal_range(t_btree *btree, const void *data,
							t_btree_node **first, t_btree_node **last);

#endif
