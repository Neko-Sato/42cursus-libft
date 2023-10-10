/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:59:58 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:10:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memswap(void *a, void *b, size_t n)
{
	unsigned char	temp;
	size_t			i;

	i = 0;
	while (i < n)
	{
		temp = ((unsigned char *)a)[i];
		((unsigned char *)a)[i] = ((unsigned char *)b)[i];
		((unsigned char *)b)[i] = temp;
		i++;
	}
}
