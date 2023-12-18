/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:21:20 by hshimizu          #+#    #+#             */
/*   Updated: 2023/12/18 10:10:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_search.h>

/*
	void		*key;
	void		*base;
	size_t		*nmemb;
	size_t		size;
	t_compar_fn	compar;
*/
void	*ft_lfind(t_lsearch_args *args)
{
	char	*result;
	size_t	count;

	result = args->base;
	count = 0;
	while (count < *args->nmemb)
	{
		if (!args->compar(args->key, result))
			return (result);
		result += args->size;
		count++;
	}
	return (NULL);
}
