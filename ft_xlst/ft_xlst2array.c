/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlst2array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:14 by hshimizu          #+#    #+#             */
/*   Updated: 2024/07/13 14:04:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_xlst.h>
#include <stdlib.h>

void	*ft_xlst2array(t_xlst *lst, size_t size, size_t *__len)
{
	size_t	len;
	char	*array;
	void	*head;

	len = ft_xlstlen(lst);
	if (len)
		array = malloc(len * size);
	else
		array = malloc(1);
	if (!array)
		return (NULL);
	head = array;
	while (lst)
	{
		ft_memcpy(array, lst->data, size);
		array += size;
		lst = lst->next;
	}
	if (__len)
		*__len = len;
	return (head);
}
