/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_node_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:26:13 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:26:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

t_slist_node	*ft_slist_node_next(t_slist_node *node)
{
	if (node)
		return (node->_next);
	return (NULL);
}