/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:24:20 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 06:03:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst/ft_lst.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	ft_lstlast(new)->next = *lst;
	*lst = new;
}
