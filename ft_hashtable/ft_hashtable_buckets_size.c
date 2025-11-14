/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_buckets_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:17:50 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/15 05:01:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

size_t	ft_hashtable_buckets_size(const t_hashtable *hashtable)
{
	return (hashtable->_buckets_size);
}
