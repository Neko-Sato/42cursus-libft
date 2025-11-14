/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_insert_multi.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 02:14:57 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 04:42:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

void	ft_hashtable_insert_multi(t_hashtable *hashtable,
		t_hashtable_node *node)
{
	unsigned long		hash;
	t_hashtable_node	**bucket;

	hash = hashtable->_hash(node->data);
	bucket = &hashtable->_buckets[hash & (hashtable->_buckets_size - 1)];
	node->_next = *bucket;
	*bucket = node;
	hashtable->_size++;
}
