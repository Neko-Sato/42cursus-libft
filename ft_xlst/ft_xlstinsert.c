/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 16:50:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_xlst.h>
#include <stdlib.h>

int	ft_xlstinsert(t_xlst **lst_ptr, int index, void *new, size_t size)
{
	t_xlst	*node;

	node = malloc(sizeof(t_xlst) + size);
	if (!node)
		return (-1);
	if (index < 0)
	{
		index += ft_xlstlen(*lst_ptr);
		if (index < 0)
			index = 0;
	}
	while (*lst_ptr && index--)
		lst_ptr = &(*lst_ptr)->next;
	node->next = *lst_ptr;
	*lst_ptr = node;
	ft_memcpy(node->data, new, size);
	return (0);
}
