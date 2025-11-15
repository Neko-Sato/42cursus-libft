/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_insert_replace.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 02:14:57 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 13:55:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

t_hashtable_node	*ft_hashtable_insert_replace(t_hashtable *hashtable,
		t_hashtable_node *node)
{
	unsigned long		hash;
	t_hashtable_node	**bucket;
	t_hashtable_node	*tmp;

	hash = hashtable->_hash(node->data);
	bucket = &hashtable->_buckets[hash & (hashtable->_buckets_size - 1)];
	while (*bucket && !hashtable->_equal((*bucket)->data, node->data))
		bucket = &(*bucket)->_next;
	tmp = *bucket;
	if (tmp)
	{
		node->_next = tmp->_next;
		tmp->_next = NULL;
		hashtable->_size++;
	}
	else
		node->_next = NULL;
	*bucket = node;
	return (tmp);
}
