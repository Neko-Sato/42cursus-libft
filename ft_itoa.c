/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:08:04 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/22 08:14:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

// static unsigned int	ft_abs(int j)
// {
// 	if (j < 0)
// 		return (-(j + 1) + 1u);
// 	else
// 		return (j);
// }

char	*ft_itoa(int n)
{
	char			buff[12];
	char			*head;
	unsigned int	m;

	if (!n)
		return (ft_strdup("0"));
	head = &buff[11];
	*head-- = '\0';
	m = ft_abs(n);
	while (1)
	{
		*head-- = '0' + m % 10;
		m /= 10;
		if (!m)
			break ;
	}
	if (n < 0)
		*head-- = '-';
	return (ft_strdup(++head));
}
