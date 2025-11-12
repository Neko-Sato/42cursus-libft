/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_node_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:17:50 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/13 08:24:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>
#include <stdlib.h>

t_hashtable_node	*ft_hashtable_node_new(size_t size)
{
	t_hashtable_node	*node;

	node = malloc(sizeof(t_hashtable_node) + size);
	if (!node)
		return (NULL);
	node->_next = NULL;
	return (node);
}
