/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distory.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:53:17 by hshimizu          #+#    #+#             */
/*   Updated: 2023/08/09 17:56:57 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_distory(void *ptrs[], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(ptrs[i++]);
	return (NULL);
}
