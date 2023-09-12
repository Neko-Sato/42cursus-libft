/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:10:34 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 12:14:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(void *src, size_t n)
{
	void	*dst;

	dst = malloc(n);
	if (!dst)
		return (NULL);
	return (ft_memcpy(dst, src, n));
}
