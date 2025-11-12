/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:26:28 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/13 08:34:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>
#include <stdlib.h>

void	ft_hashtable_destroy(t_hashtable *hashtable)
{
	size_t				i;
	t_hashtable_node	*next;
	t_hashtable_node	*tmp;

	i = 0;
	while (i < hashtable->_buckets_size)
	{
		tmp = hashtable->_buckets[i];
		while (tmp)
		{
			next = ft_hashtable_extract(hashtable, tmp, i);
			ft_hashtable_node_delete(tmp);
			tmp = next;
		}
		i++;
	}
	free(hashtable->_buckets);
}
