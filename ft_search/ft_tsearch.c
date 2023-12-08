/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:40:28 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/09 03:20:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stdlib.h>

void	*ft_tsearch(void *key, void **rootp, t_search_compar compar)
{
	t_search_node	**nodep;

	if (!rootp)
		return (NULL);
	nodep = __ft_search_getnodep(key, rootp, compar);
	if (!*nodep)
	{
		*nodep = malloc(sizeof(**nodep));
		if (!*nodep)
			return (NULL);
		(*nodep)->key = key;
		(*nodep)->left = NULL;
		(*nodep)->right = NULL;
	}
	return (nodep);
}
