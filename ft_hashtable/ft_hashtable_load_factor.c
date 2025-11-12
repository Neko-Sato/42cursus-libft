/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_load_factor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:20:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/13 08:21:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

float	ft_hashtable_load_factor(const t_hashtable *hashtable)
{
	return (hashtable->_size / (float)hashtable->_buckets_size);
}
