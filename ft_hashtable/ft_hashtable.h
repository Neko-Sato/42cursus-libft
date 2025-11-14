/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:03:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 02:36:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# include <stddef.h>

# define _HASHTABLE_INITIAL_BUCKETS_SIZE 16

typedef struct s_hashtable_node
{
	struct s_hashtable_node	*_next;
	char					data[];
}							t_hashtable_node;

t_hashtable_node			*ft_hashtable_node_new(size_t size);
void						ft_hashtable_node_delete(t_hashtable_node *node);
t_hashtable_node			*ft_hashtable_node_next(t_hashtable_node *node);

typedef struct s_hashtable
{
	t_hashtable_node		**_buckets;
	size_t					_buckets_size;
	size_t					_size;
	int						(*_equal)(const void *, const void *);
	unsigned long			(*_hash)(const void *);
}							t_hashtable;

int							ft_hashtable_init(t_hashtable *hashtable,
								int (*equal)(const void *, const void *),
								unsigned long (*hash)(const void *));
void						ft_hashtable_destroy(t_hashtable *hashtable);

int							ft_hashtable_insert_unique(t_hashtable *hashtable,
								t_hashtable_node *node);
t_hashtable_node			*ft_hashtable_insert_replace(t_hashtable *hashtable,
								t_hashtable_node *node);
void						ft_hashtable_insert_multi(t_hashtable *hashtable,
								t_hashtable_node *node);
t_hashtable_node			*ft_hashtable_extract(t_hashtable *hashtable,
								t_hashtable_node *node, size_t buckets_index);

size_t						ft_hashtable_size(const t_hashtable *hashtable);
t_hashtable_node			*ft_hashtable_find(const t_hashtable *hashtable,
								const void *data, size_t *buckets_index);

t_hashtable_node			*ft_hashtable_buckets(t_hashtable *hashtable,
								size_t index);
size_t						ft_hashtable_buckets_size(
								const t_hashtable *hashtable);
float						ft_hashtable_load_factor(
								const t_hashtable *hashtable);
int							ft_hashtable_rehash(t_hashtable *hashtable,
								size_t n, float load_factor);

#endif
