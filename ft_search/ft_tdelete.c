/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdelete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:36:05 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/09 03:13:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <stdlib.h>

static void	case_leaf(t_search_node **nodep);
static void	case_one_node(t_search_node **nodep);
static void	case_two_node(t_search_node **nodep);

void	*ft_tdelete(void *key, void **rootp, t_search_compar compar)
{
	t_search_node	**nodep;

	if (!rootp)
		return (NULL);
	nodep = __ft_search_getnodep(key, rootp, compar);
	if ((*nodep)->left && (*nodep)->right)
		case_two_node(nodep);
	else if ((*nodep)->left || (*nodep)->right)
		case_one_node(nodep);
	else
		case_leaf(nodep);
	return (nodep);
}

static void	case_leaf(t_search_node **nodep)
{
	free(*nodep);
	*nodep = NULL;
}

static void	case_one_node(t_search_node **nodep)
{
	t_search_node	*temp;

	if ((*nodep)->left)
		temp = (*nodep)->left;
	else
		temp = (*nodep)->right;
	free(*nodep);
	*nodep = temp;
}

static void	case_two_node(t_search_node **nodep)
{
	t_search_node	**rightmin;
	t_search_node	*temp;

	rightmin = __ft_search_minnodep((void **)&(*nodep)->right);
	temp = *rightmin;
	*rightmin = (*rightmin)->right;
	temp->left = (*nodep)->left;
	temp->right = (*nodep)->right;
	free(*nodep);
	*nodep = temp;
}
