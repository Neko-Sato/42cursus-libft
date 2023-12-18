/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 16:38:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_xlst.h>
#include <stdlib.h>

int	ft_xlstpop(t_xlst **lst_ptr, int index, void *dst, size_t size)
{
	t_xlst	*node;

	if (index < 0)
	{
		index += ft_xlstlen(*lst_ptr);
		if (index < 0)
			return (-1);
	}
	while (*lst_ptr && index--)
		lst_ptr = &(*lst_ptr)->next;
	node = *lst_ptr;
	if (!node)
		return (-1);
	*lst_ptr = node->next;
	if (dst)
		ft_memcpy(dst, node->data, size);
	free(node);
	return (0);
}
