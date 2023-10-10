/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlst2array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:18:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>
#include <ft_string.h>
#include <stdlib.h>

void	*ft_xlst2array(void *lst, size_t size, size_t *__len)
{
	size_t	len;
	void	*array;
	void	*head;

	len = ft_xlstlen(lst, size);
	array = malloc(len * size);
	if (!array)
		return (NULL);
	head = array;
	while (lst)
	{
		ft_memcpy(array, lst, size);
		array += size;
		lst = *(void **)(lst + size);
	}
	if (__len)
		*__len = len;
	return (head);
}
