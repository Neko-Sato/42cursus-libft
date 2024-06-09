/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:06:26 by hshimizu          #+#    #+#             */
/*   Updated: 2024/06/10 04:56:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_xlst.h>
#include <stdlib.h>

int	ft_xlstremove(t_xlst **lst_ptr, void *value, size_t size)
{
	t_xlst	*lst;

	while (*lst_ptr)
	{
		lst = *lst_ptr;
		if (!ft_memcmp(value, &lst->data, size))
		{
			*lst_ptr = lst->next;
			free(lst);
			return (0);
		}
		lst_ptr = &lst->next;
	}
	return (-1);
}
