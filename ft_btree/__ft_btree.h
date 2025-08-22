/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __ft_btree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:06:59 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/22 16:01:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BTREE_H
# define __FT_BTREE_H

# include <ft_btree/ft_btree.h>

void	__ft_btree_insert(t_btree *btree, t_btree_node *pos,
			t_btree_node *node);

void	__ft_btree_fixup_insert(t_btree *btree, t_btree_node *node);
void	__ft_btree_fixup_extract(t_btree *btree, t_btree_node *node);

#endif
