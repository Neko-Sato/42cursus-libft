/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/19 22:55:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_xlstinsert(void *lst_ptr, size_t size, void *new, int index)
{
	void	*node;
	void	*temp;

	node = malloc(size + sizeof(void *));
	if (!node)
		return (-1);
	ft_memcpy(node, new, size);
	if (index < 0)
	{
		index += ft_xlstlen(*(void **)lst_ptr, size);
		if (index < 0)
			index = 0;
	}
	temp = lst_ptr;
	while (*(void **)temp && index--)
		temp = *(void **)temp + size;
	*(void **)(node + size) = *(void **)temp;
	*(void **)temp = node;
	return (0);
}
