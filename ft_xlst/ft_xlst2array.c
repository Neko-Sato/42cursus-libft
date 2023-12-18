/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlst2array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 08:58:19 by hshimizu         ###   ########.fr       */
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
	array = malloc(len * size);
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
