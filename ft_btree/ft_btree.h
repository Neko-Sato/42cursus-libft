/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:27:42 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 05:28:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stddef.h>

typedef struct s_btree_node
{
	struct s_btree_node	*left;
	struct s_btree_node	*right;
	char				data[];
}						t_btree_node;

typedef struct s_btree
{
	size_t				_type;
	t_btree_node		*_root;
}						t_btree;

#endif
