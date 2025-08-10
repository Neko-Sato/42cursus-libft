/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_node_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:56:05 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:13:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>
#include <stdlib.h>

t_dlist_node	*ft_dlist_node_new(size_t size)
{
	t_dlist_node	*node;

	node = malloc(sizeof(t_dlist_node) + size);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
