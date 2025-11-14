/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_insert_unique.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 02:14:57 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 04:42:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

int	ft_hashtable_insert_unique(t_hashtable *hashtable, t_hashtable_node *node)
{
	unsigned long		hash;
	t_hashtable_node	**bucket;
	t_hashtable_node	*tmp;

	hash = hashtable->_hash(node->data);
	bucket = &hashtable->_buckets[hash & (hashtable->_buckets_size - 1)];
	tmp = *bucket;
	while (tmp && !hashtable->_equal(tmp->data, node->data))
		tmp = tmp->_next;
	if (tmp)
		return (1);
	node->_next = *bucket;
	*bucket = node;
	hashtable->_size++;
	return (0);
}
