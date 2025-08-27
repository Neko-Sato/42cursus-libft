/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:13:03 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/27 12:16:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>
#include <ft_utils/ft_utils.h>

void	*ft_reverse(void *base, size_t nmemb, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = nmemb;
	while (i < j)
		ft_memswap((char *)base + size * i++, (char *)base + size * --j, size);
	return (base);
}
