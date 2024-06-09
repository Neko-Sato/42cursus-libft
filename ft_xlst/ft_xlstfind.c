/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstfind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:06:26 by hshimizu          #+#    #+#             */
/*   Updated: 2024/06/10 04:47:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_xlst.h>

int	ft_xlstfind(t_xlst *lst, void *find, size_t size, size_t *index)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		if (!ft_memcmp(find, &lst->data, size))
		{
			*index = count;
			return (0);
		}
		lst = lst->next;
		count++;
	}
	return (-1);
}
