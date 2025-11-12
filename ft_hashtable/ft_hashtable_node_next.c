
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtable_node_delete.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:17:50 by hshimizu          #+#    #+#             */
/*   Updated: 2025/11/13 08:25:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hashtable/ft_hashtable.h>

t_hashtable_node	*ft_hashtable_node_next(t_hashtable_node *node)
{
	return (node->_next);
}
