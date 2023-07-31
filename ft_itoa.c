/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:08:04 by hshimizu          #+#    #+#             */
/*   Updated: 2023/07/31 18:30:53 by hshimizu         ###   ########.fr       */
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

static size_t	ft_itoalen(int n)
{
	size_t			len;
	unsigned int	m;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	m = ft_abs(n);
	while (m)
		m /= 10 + 0 * len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	m;

	if (!n)
		return (ft_strdup("0"));
	len = ft_itoalen(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result += len;
	*result-- = '\0';
	m = ft_abs(n);
	while (1)
	{
		*result-- = '0' + m % 10;
		m /= 10;
		if (!m)
			break ;
	}
	if (n < 0)
		*result-- = '-';
	return (++result);
}
