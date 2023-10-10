/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:43:13 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 23:02:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (1)
		{
			if (!lst->next)
				break ;
			lst = lst->next;
		}
	}
	return (lst);
}
