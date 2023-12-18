/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:43:49 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 16:34:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SEARCH_H
# define FT_SEARCH_H

# include "ft_stdlib.h"
# include <search.h>

//	tsearch
typedef struct s_search_node
{
	void					*key;
	struct s_search_node	*left;
	struct s_search_node	*right;
}							t_search_node;

typedef void				(*t_search_action)(void *nodep, VISIT which,
					int depth);

t_search_node				**__ft_search_getnodep(void *key, void **rootp,
								t_compar_fn compar);
t_search_node				**__ft_search_minnodep(void **rootp);

void						*ft_tsearch(void *key, void **rootp,
								t_compar_fn compar);
void						*ft_tfind(void *key, void **rootp,
								t_compar_fn compar);
void						*ft_tdelete(void *key, void **rootp,
								t_compar_fn compar);
void						ft_twalk(void *root, t_search_action action);
void						ft_tdestroy(void *root, t_free_fn free_node);

//	lsearch
/*
	structure because the number of arguments is limited by norm.
*/
typedef struct s_lsearch_args
{
	void					*key;
	void					*base;
	size_t					*nmemb;
	size_t					size;
	t_compar_fn				compar;
}							t_lsearch_args;

void						*ft_lsearch(t_lsearch_args *args);
void						*ft_lfind(t_lsearch_args *args);

#endif