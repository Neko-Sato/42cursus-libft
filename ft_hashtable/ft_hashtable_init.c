/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:26:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 02:40:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>
#include <ft_string/ft_string.h>
#include <stdlib.h>

int	ft_hashtable_init(t_hashtable *hashtable, int (*equal)(const void *,
			const void *), unsigned long (*hash)(const void *))
{
	t_hashtable_node	**buckets;
	size_t				buckets_size;

	buckets_size = _HASHTABLE_INITIAL_BUCKETS_SIZE;
	buckets = malloc(sizeof(t_hashtable_node *) * buckets_size);
	if (!buckets)
		return (-1);
	ft_memset(buckets, 0, sizeof(t_hashtable_node *) * buckets_size);
	hashtable->_buckets = buckets;
	hashtable->_buckets_size = buckets_size;
	hashtable->_size = 0;
	hashtable->_equal = equal;
	hashtable->_hash = hash;
	return (0);
}
