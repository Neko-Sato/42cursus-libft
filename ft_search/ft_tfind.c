/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:02:31 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/08 22:09:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stddef.h>

void	*ft_tfind(void *key, void **rootp, t_search_compar compar)
{
	t_search_node	**nodep;

	if (!rootp)
		return (NULL);
	nodep = __ft_search_getnodep(key, rootp, compar);
	if (!*nodep)
		return (NULL);
	return (nodep);
}