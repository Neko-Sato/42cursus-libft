/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __minnodep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:40:50 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/09 03:41:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stddef.h>

t_search_node	**__ft_search_minnodep(void **rootp)
{
	t_search_node	**nodep;

	nodep = (t_search_node **)rootp;
	if (!*nodep)
		return (NULL);
	while ((*nodep)->left)
		nodep = &(*nodep)->left;
	return (nodep);
}
