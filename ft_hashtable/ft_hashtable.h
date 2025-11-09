/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:03:27 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/09 17:38:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# include <stddef.h>

typedef struct s_hashtable_node
{
	struct s_hashtable_node	*_next;
	char					data[];
}							t_hashtable_node;

typedef struct s_hashtable
{
	t_hashtable_node		**_buckets;
	size_t					_buckets_size;
	size_t					_size;
	int						(*_equal)(const void *, const void *);
	unsigned long			(*_hash)(const void *);
}							t_hashtable;

int							ft_hashtable_init(t_hashtable *hashtable,
								int (*less)(const void *, const void *),
								unsigned long (*hash)(const void *));
void						ft_hashtable_destroy(t_hashtable *hashtable);

int							ft_hashtable_insert_unique(t_hashtable *hashtable,
								t_hashtable_node *node);
t_hashtable_node			*ft_hashtable_insert_replace(t_hashtable *hashtable,
								t_hashtable_node *node);
void						ft_hashtable_insert_multi(t_hashtable *hashtable,
								t_hashtable_node *node);
t_hashtable_node			*ft_hashtable_extract(t_hashtable *hashtable,
								t_hashtable_node *node);

typedef struct s_hashtable_iterator
{
	t_hashtable			*_hashtable;
	size_t				*_inedx;
	t_hashtable_node	*_current;
}	t_hashtable_iterator;


t_hashtable_node			*ft_hashtable_head(const t_hashtable *hashtable);
t_hashtable_node			*ft_hashtable_end(const t_hashtable *hashtable);
t_hashtable_node			*ft_hashtable_find(const t_hashtable *hashtable, const void *data);

#endif
