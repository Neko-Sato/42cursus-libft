/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:15:52 by hshimizu          #+#    #+#             */
/*   Updated: 2023/05/22 10:52:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (*lst)
	{
		while (1)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			if (!next)
				break ;
			*lst = next;
		}
		*lst = NULL;
	}
}
