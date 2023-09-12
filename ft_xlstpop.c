/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:48:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:49:26 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_xlstpop(void *lst_ptr, size_t size, int index)
{
	void	*ret;
	int		len;
	void	*node;
	void	*temp;

	len = ft_xlstlen(*(void **)lst_ptr, size);
	if (!len)
		return (NULL);
	if (index < 0)
		index += len;
	if (index < 0 || len < index)
		return (NULL);
	ret = malloc(size);
	if (!ret)
		return (NULL);
	if (index == 0)
		temp = lst_ptr;
	else
		temp = ft_xlstat(*(void **)lst_ptr, size, index - 1) + size;
	node = *(void **)temp;
	ft_memcpy(ret, node, size);
	*(void **)temp = *(void **)(node + size);
	free(node);
	return (ret);
}
