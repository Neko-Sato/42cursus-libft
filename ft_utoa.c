/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:08:04 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/22 08:18:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_utoa(unsigned int n)
{
	char	buf[11];
	char	*head;

	if (!n)
		return (ft_strdup("0"));
	head = &buf[10];
	*head-- = '\0';
	while (1)
	{
		*head-- = '0' + n % 10;
		n /= 10;
		if (!n)
			break ;
	}
	return (ft_strdup(++head));
}
