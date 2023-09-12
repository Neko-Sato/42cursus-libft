/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:49:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 16:48:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_xlstclear(void *lst_ptr, size_t size)
{
	while (*(void **)lst_ptr)
		ft_xlstdel(lst_ptr, size, 0);
}
