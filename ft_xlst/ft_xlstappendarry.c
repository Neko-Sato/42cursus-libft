/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstappendarry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:32 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/01 02:00:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>

int	ft_xlstappendarry(t_xlst **lst_ptr, void *arry, size_t len, size_t size)
{
	t_xlst	**last;
	t_xlst	*temp;

	if (!arry || !len)
		return (0);
	temp = NULL;
	while (len--)
	{
		if (ft_xlstappend(lst_ptr, arry, size))
		{
			ft_xlstclear(&temp);
			return (-1);
		}
		arry = (char *)arry + size;
	}
	last = lst_ptr;
	while (*last)
		last = &(*last)->next;
	*last = temp;
	return (0);
}
