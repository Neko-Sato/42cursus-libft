/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:58:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:49:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_xlstlen(void *lst, size_t size)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = *(void **)(lst + size);
		count++;
	}
	return (count);
}
