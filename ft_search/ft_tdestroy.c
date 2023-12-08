/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdestory.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 03:02:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/09 03:17:41 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stdlib.h>

static void	recurse(t_search_node *root, t_search_free_node free_node);

void	ft_tdestroy(void *root,
					t_search_free_node free_node)
{
	if (root)
		recurse(root, free_node);
}

static void	recurse(t_search_node *root, t_search_free_node free_node)
{
	if (root->left)
		recurse(root->left, free_node);
	if (root->right)
		recurse(root->right, free_node);
	free_node(root->key);
	free(root);
}
