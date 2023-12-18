/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:58:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 10:07:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>
#include <stddef.h>

void	*ft_xlstat(t_xlst *lst, int index)
{
	int	count;

	count = 0;
	if (index < 0)
	{
		index += ft_xlstlen(lst);
		if (index < 0)
			return (NULL);
	}
	while (lst && count < index)
	{
		lst = lst->next;
		count++;
	}
	if (!lst)
		return (NULL);
	return (lst->data);
}
