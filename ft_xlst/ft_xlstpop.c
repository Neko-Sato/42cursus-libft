/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:18:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>
#include <ft_string.h>
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
	temp = lst_ptr;
	while (*(void **)temp && index--)
		temp = *(void **)temp + size;
	node = *(void **)temp;
	if (!node)
		return (-1);
	*(void **)temp = *(void **)(node + size);
	if (dst)
		ft_memcpy(dst, node, size);
	free(node);
	return (0);
}
