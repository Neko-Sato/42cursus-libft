/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/19 23:51:25 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_xlstat(void *lst, size_t size, int index, void *dst)
{
	int	count;

	count = 0;
	if (index < 0)
	{
		index += ft_xlstlen(lst, size);
		if (index < 0)
			return (-1);
	}
	while (lst && count < index)
	{
		lst = *(void **)(lst + size);
		count++;
	}
	if (!lst)
		return (-1);
	ft_memcpy(dst, lst, size);
	return (0);
}
