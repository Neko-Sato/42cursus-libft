/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:47:32 by hshimizu          #+#    #+#             */
/*   Updated: 2024/06/10 04:44:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>

int	ft_xlstcat(t_xlst **lst_ptr, t_xlst **lst)
{
	while (*lst_ptr)
		lst_ptr = &(*lst_ptr)->next;
	*lst_ptr = *lst;
	*lst = NULL;
	return (0);
}
