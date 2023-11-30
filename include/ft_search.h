/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:43:49 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/30 14:44:55 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEARCH_H
# define FT_SEARCH_H

# include <search.h>

typedef struct s_entry
{
	void			*key;
	struct s_entry	*left;
	struct s_entry	*right;
}					t_entry;

typedef int			(*t_search_compar)(void *, void *);
typedef void		(*t_search_action)(void *nodep, VISIT which, int depth);
typedef void		(*t_search_free_node)(void *nodep);

void				*ft_tsearch(void *key, void **rootp,
						t_search_compar compar);
void				*ft_tfind(void *key, void **rootp, t_search_compar compar);
void				*ft_tdelete(void *key, void **rootp,
						t_search_compar compar);
void				ft_twalk(void *root, t_search_action action);
void				ft_tdestroy(void *root, t_search_free_node free_node);

#endif