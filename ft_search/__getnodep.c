/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __getnodep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:40:50 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 09:09:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>

t_search_node	**__ft_search_getnodep(void *key, void **rootp,
		t_compar_fn compar)
{
	t_search_node	**nodep;
	int				cmp;

	nodep = (t_search_node **)rootp;
	while (*nodep)
	{
		cmp = compar(key, (*nodep)->key);
		if (cmp == 0)
			break ;
		else if (cmp < 0)
			nodep = &(*nodep)->left;
		else if (0 < cmp)
			nodep = &(*nodep)->right;
	}
	return (nodep);
}
