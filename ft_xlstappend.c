/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/19 23:35:20 by hshimizu         ###   ########.fr       */
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
	temp = lst_ptr;
	while (*(void **)temp)
		temp = *(void **)temp + size;
	*(void **)temp = node;
	return (0);
}
