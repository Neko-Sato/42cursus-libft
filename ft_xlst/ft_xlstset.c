/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:18:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>
#include <ft_string.h>
#include <stddef.h>

int	ft_xlstset(void *lst, size_t size, int index, void *src)
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
	ft_memcpy(lst, src, size);
	return (0);
}
