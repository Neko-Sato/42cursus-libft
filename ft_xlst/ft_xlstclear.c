/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:49:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 09:03:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_xlst.h>
#include <stdlib.h>

void	ft_xlstclear(t_xlst **lst_ptr)
{
	while (*lst_ptr)
		ft_xlstdel(lst_ptr, 0);
}
