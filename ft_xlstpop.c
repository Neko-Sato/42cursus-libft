/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/19 23:15:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_xlstpop(void *lst_ptr, size_t size, int index, void *dst)
{
	void	*node;
	void	*temp;

	if (index < 0)
	{
		index += ft_xlstlen(*(void **)lst_ptr, size);
		if (index < 0)
			return (-1);
	}
	if (!index)
		temp = lst_ptr;
	else
	{
		temp = ft_xlstat(*(void **)lst_ptr, size, index - 1);
		if (!temp)
			return (-1);
		temp += size;
	}
	node = *(void **)temp;
	*(void **)temp = *(void **)(node + size);
	if (dst)
		ft_memcpy(dst, node, size);
	free(node);
	return (0);
}
