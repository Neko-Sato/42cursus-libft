/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:48:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_xlstappend(void *lst_ptr, size_t size, void *new)
{
	void	*node;
	void	*temp;

	node = malloc(size + sizeof(void *));
	if (!node)
		return (-1);
	ft_memcpy(node, new, size);
	*(void **)(node + size) = NULL;
	temp = ft_xlstat(*(void **)lst_ptr, size, -1);
	if (temp)
		lst_ptr = temp + size;
	*(void **)lst_ptr = node;
	return (0);
}
