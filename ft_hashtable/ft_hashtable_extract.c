/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_extract.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:21:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 13:59:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

t_hashtable_node	*ft_hashtable_extract(t_hashtable *hashtable,
		t_hashtable_node *node, size_t buckets_index)
{
	t_hashtable_node	**tmp;

	tmp = &hashtable->_buckets[buckets_index];
	while (*tmp != node)
		tmp = &(*tmp)->_next;
	*tmp = node->_next;
	node->_next = NULL;
	hashtable->_size--;
	return (*tmp);
}
