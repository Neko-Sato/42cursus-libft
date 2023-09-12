/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:49:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:49:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_xlstdel(void *lst_ptr, size_t size, int index)
{
	int		len;
	void	*node;
	void	*temp;

	len = ft_xlstlen(*(void **)lst_ptr, size);
	if (!len)
		return ;
	if (index < 0)
		index += len;
	if (index < 0 || len < index)
		return ;
	if (index == 0)
		temp = lst_ptr;
	else
		temp = ft_xlstat(*(void **)lst_ptr, size, index - 1) + size;
	node = *(void **)temp;
	*(void **)temp = *(void **)(node + size);
	free(node);
}
