/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:48:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_xlstat(void *lst, size_t size, int index)
{
	int		count;

	count = 0;
	if (index < 0)
	{
		index += ft_xlstlen(lst, size);
		if (index < 0)
			return (NULL);
	}
	while (lst && count < index)
	{
		lst = *(void **)(lst + size);
		count++;
	}
	return (lst);
}
