/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 05:24:49 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/08 05:28:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_XLIST_H
# define FT_XLIST_H

# include <stddef.h>

typedef struct s_xlist_node
{
	struct s_xlist	*next;
	char			data[];
}					t_xlist_node;

typedef struct s_xlist
{
	size_t			_type;
	t_xlist_node	*_head;
}					t_xlist;

#endif
