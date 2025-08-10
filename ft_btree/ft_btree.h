/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:27:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 06:06:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stddef.h>

typedef struct s_btree_node
{
	struct s_btree_node	*left;
	struct s_btree_node	*right;
	char				data[];
}						t_btree_node;

t_btree_node			*ft_btree_node_new(size_t size);
void					ft_btree_node_delete(t_btree_node *node);

typedef struct s_btree
{
	t_btree_node		*_root;
	int					(*_compar)(const void *, const void *);
	size_t				_size;
	int					_alow_dup;
}						t_btree;

int						ft_btree_init(t_btree *btree,
							int (*compar)(const void *, const void *),
							int alow_dup);
void					ft_btree_destroy(t_btree *btree);

int						ft_btree_insert(t_btree *btree, t_btree_node *node,
							t_btree_node **dup);
void					ft_btree_erase(t_btree *btree, t_btree_node *node);

t_btree_node			*ft_btree_find(t_btree *btree, const void *data);
t_btree_node			*ft_btree_lower_bound(t_btree *btree, const void *data);
t_btree_node			*ft_btree_upper_bound(t_btree *btree, const void *data);
void					ft_btree_equal_range(t_btree *btree, const void *data,
							t_btree_node **first, t_btree_node **last);

t_btree_node			*ft_btree_head(t_btree *btree);
t_btree_node			*ft_btree_next(t_btree_node *node);

#endif
