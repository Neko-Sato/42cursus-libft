/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:57:39 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 05:35:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_dlist/ft_dlist.h>

int	ft_dlist_init(t_dlist *dlist)
{
	dlist->_head = NULL;
	dlist->_tail = NULL;
	dlist->_size = 0;
	return (0);
}
