/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twalk_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:38:36 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/21 07:55:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stdlib.h>

static void	trecurse(t_search_node *node, t_search_action action, void *closure);

void	ft_twalk_r(void *root, t_search_action_r action, void *closure)
{
	if (root && action)
		trecurse(root, action, closure);
}

static void	trecurse(t_search_node *node, t_search_action action, void *closure)
{
	if (!node->left && !node->right)
		action(node, leaf, closure);
	else
	{
		action(node, preorder, closure);
		if (node->left)
			trecurse(node->left, action, closure);
		action(node, postorder, closure);
		if (node->right)
			trecurse(node->right, action, closure);
		action(node, endorder, closure);
	}
}
