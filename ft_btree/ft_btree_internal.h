/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 06:08:37 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/11 11:22:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_INTERNAL_H
# define FT_BTREE_INTERNAL_H

# include <ft_btree/ft_btree.h>

t_btree_node	*__ft_btree_rotate_left(t_btree_node *node);
t_btree_node	*__ft_btree_rotate_right(t_btree_node *node);
t_btree_node	*__ft_btree_rotate_left_right(t_btree_node *node);
t_btree_node	*__ft_btree_rotate_right_left(t_btree_node *node);

#endif
