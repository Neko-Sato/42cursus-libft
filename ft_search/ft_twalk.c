/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:38:36 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/21 07:58:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stdlib.h>

static void	trecurse(t_search_node *node, t_tsearch_action action, int depth);

void	ft_twalk(void *root, t_tsearch_action action)
{
	if (root && action)
		trecurse(root, action, 0);
}

static void	trecurse(t_search_node *node, t_tsearch_action action, int depth)
{
	if (!node->left && !node->right)
		action(node, leaf, depth);
	else
	{
		action(node, preorder, depth);
		if (node->left)
			trecurse(node->left, action, depth + 1);
		action(node, postorder, depth);
		if (node->right)
			trecurse(node->right, action, depth + 1);
		action(node, endorder, depth);
	}
}
