/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_node_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:28:25 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:28:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

t_dlist_node	*ft_dlist_node_prev(t_dlist_node *node)
{
	if (node)
		return (node->_prev);
	return (NULL);
}