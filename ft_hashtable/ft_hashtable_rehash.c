/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_rehash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:03:24 by hshimizu          #+#    #+#             */
/*   Updated: 2026/05/20 20:53:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>
#include <ft_string/ft_string.h>
#include <stdlib.h>
#include <stdint.h>

static inline void	_internal(t_hashtable *hashtable,
		t_hashtable_node **new_buckets, size_t new_buckets_size)
{
	size_t				i;
	t_hashtable_node	*tmp;
	t_hashtable_node	**head;

	i = 0;
	while (i < hashtable->_buckets_size)
	{
		while (hashtable->_buckets[i])
		{
			tmp = hashtable->_buckets[i];
			hashtable->_buckets[i] = tmp->_next;
			head = &new_buckets[hashtable->_hash(tmp->data) & (new_buckets_size
					- 1)];
			tmp->_next = *head;
			*head = tmp;
		}
		i++;
	}
}

static inline size_t	_next_size(size_t n, float f)
{
	size_t	q;

	if (n > (double)SIZE_MAX * f)
		return (SIZE_MAX);
	q = n / f;
	if (q * f < (double)n)
		q++;
	if (q == 0)
		return (1);
	q--;
	q |= q >> 1;
	q |= q >> 2;
	q |= q >> 4;
	q |= q >> 8;
	q |= q >> 16;
	q |= q >> 32;
	return (q + 1);
}

int	ft_hashtable_rehash(t_hashtable *hashtable, size_t n, float load_factor)
{
	t_hashtable_node	**new_buckets;
	size_t				new_buckets_size;

	if (load_factor <= 0.f)
		return (-1);
	new_buckets_size = _next_size(n, load_factor);
	if (new_buckets_size < hashtable->_buckets_size)
		return (0);
	new_buckets = malloc(sizeof(t_hashtable_node *) * new_buckets_size);
	if (!new_buckets)
		return (-1);
	ft_memset(new_buckets, 0, sizeof(t_hashtable_node *) * new_buckets_size);
	_internal(hashtable, new_buckets, new_buckets_size);
	free(hashtable->_buckets);
	hashtable->_buckets = new_buckets;
	hashtable->_buckets_size = new_buckets_size;
	return (0);
}
