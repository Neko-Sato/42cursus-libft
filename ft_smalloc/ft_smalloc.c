/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:13:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/18 19:57:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_smalloc(size_t size)
{
	size_t	*ret;

	if (sizeof(size_t) + size < size)
		return (NULL);
	ret = malloc(sizeof(size_t) + size);
	if (!ret)
		return (NULL);
	ret[0] = size;
	return (&ret[1]);
}
