/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_node_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:56:05 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:27:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>
#include <stdlib.h>

t_slist_node	*ft_slist_node_new(size_t size)
{
	t_slist_node	*node;

	node = malloc(sizeof(t_slist_node) + size);
	if (!node)
		return (NULL);
	node->_next = NULL;
	return (node);
}
