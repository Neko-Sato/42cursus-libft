/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:27:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 16:19:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stddef.h>

typedef enum e__btree_color
{
	_BTREE_RED,
	_BTREE_BLACK
}						t__btree_color;

typedef struct s_btree_node
{
	struct s_btree_node	*_left;
	struct s_btree_node	*_parent;
	struct s_btree_node	*_right;
	t__btree_color		_color;
	char				data[];
}						t_btree_node;

t_btree_node			*ft_btree_node_new(size_t size);
void					ft_btree_node_delete(t_btree_node *node);
t_btree_node			*ft_btree_node_next(const t_btree_node *node);
t_btree_node			*ft_btree_node_prev(const t_btree_node *node);

typedef struct s_btree
{
	t_btree_node		*_root;
	t_btree_node		*_head;
	int					(*_less)(const void *, const void *);
	size_t				_size;
}						t_btree;

int						ft_btree_init(t_btree *btree, int (*less)(const void *,
								const void *));
void					ft_btree_destroy(t_btree *btree);
void					ft_btree_move(t_btree *dst, t_btree *src);

int						ft_btree_insert_unique(t_btree *btree,
							t_btree_node *node);
t_btree_node			*ft_btree_insert_replace(t_btree *btree,
							t_btree_node *node);
void					ft_btree_insert_multi(t_btree *btree,
							t_btree_node *node);
t_btree_node			*ft_btree_extract(t_btree *btree, t_btree_node *node);

t_btree_node			*ft_btree_head(const t_btree *btree);
t_btree_node			*ft_btree_end(const t_btree *btree);
t_btree_node			*ft_btree_find(const t_btree *btree, const void *data);
t_btree_node			*ft_btree_lower_bound(const t_btree *btree,
							const void *data);
t_btree_node			*ft_btree_upper_bound(const t_btree *btree,
							const void *data);

void					ft__btree_insert(t_btree *btree, t_btree_node *pos,
							t_btree_node *node);
void					ft__btree_replace(t_btree_node *pos,
							t_btree_node *node);
void					ft__btree_fixup(t_btree *btree, t_btree_node *node);

#endif
