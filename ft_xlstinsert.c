/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:49:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_xlstinsert(void *lst_ptr, size_t size, void *new, int index)
{
	int		len;
	void	*node;
	void	*temp;

	node = malloc(size + sizeof(void *));
	if (!node)
		return (-1);
	ft_memcpy(node, new, size);
	len = ft_xlstlen(*(void **)lst_ptr, size);
	if (index < 0)
		index += len;
	if (index < 0)
		index = 0;
	else if (len < index)
		index = len;
	if (index == 0)
		temp = lst_ptr;
	else
		temp = ft_xlstat(*(void **)lst_ptr, size, index - 1) + size;
	*(void **)(node + size) = *(void **)temp;
	*(void **)temp = node;
	return (0);
}
