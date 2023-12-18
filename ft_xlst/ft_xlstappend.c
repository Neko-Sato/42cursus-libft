/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 16:49:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>
#include <ft_string.h>
#include <stdlib.h>

int	ft_xlstappend(t_xlst **lst_ptr, void *new, size_t size)
{
	t_xlst	*node;

	node = malloc(sizeof(t_xlst) + size);
	if (!node)
		return (-1);
	while (*lst_ptr)
		lst_ptr = &(*lst_ptr)->next;
	*lst_ptr = node;
	node->next = NULL;
	ft_memcpy(node->data, new, size);
	return (0);
}
