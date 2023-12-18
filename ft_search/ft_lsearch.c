/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:21:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 09:38:32 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>
#include <ft_string.h>

/*
	void		*key;
	void		*base;
	size_t		*nmemb;
	size_t		size;
	t_compar_fn	compar;
*/
void	*ft_lsearch(t_lsearch_args *args)
{
	void	*result;

	result = ft_lfind(args);
	if (!result)
	{
		result = ((char *)args->base)[*args->nmemb * args->size];
		memcpy(result, args->key, args->size);
		(*args->nmemb)++;
	}
	return (result);
}
