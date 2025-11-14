/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_buckets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:17:50 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 05:01:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

t_hashtable_node	*ft_hashtable_buckets(t_hashtable *hashtable, size_t index)
{
	return (hashtable->_buckets[index]);
}
