/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:58:25 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:43:24 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_slist/ft_slist.h>

void	ft_slist_destroy(t_slist *slist)
{
	t_slist_node	*tmp;

	tmp = ft_slist_head(slist);
	while (tmp)
		tmp = ft_slist_erase(slist, tmp);
}
