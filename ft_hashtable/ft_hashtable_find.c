/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:21:54 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 05:34:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

t_hashtable_node	*ft_hashtable_find(const t_hashtable *hashtable,
		const void *data, size_t *buckets_index)
{
	size_t				index;
	t_hashtable_node	*tmp;

	index = hashtable->_hash(data) % hashtable->_buckets_size;
	tmp = hashtable->_buckets[index];
	while (tmp)
	{
		if (hashtable->_equal(tmp->data, data))
		{
			if (buckets_index)
				*buckets_index = index;
			return (tmp);
		}
		tmp = tmp->_next;
	}
	return (NULL);
}
