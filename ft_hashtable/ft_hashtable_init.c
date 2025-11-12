/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:26:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/13 08:39:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

int	ft_hashtable_init(t_hashtable *hashtable, int (*equal)(const void *,
			const void *), unsigned long (*hash)(const void *))
{
	hashtable->_buckets = NULL;
	hashtable->_buckets_size = 0;
	hashtable->_size = 0;
	hashtable->_equal = equal;
	hashtable->_hash = hash;
	return (0);
}
