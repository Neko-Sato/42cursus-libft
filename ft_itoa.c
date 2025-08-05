/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:15:19 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/05 20:20:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			buf[11];
	char			*tmp;
	unsigned int	un;

	tmp = &buf[11];
	if (n < 0)
		un = -n;
	else
		un = n;
	while (1)
	{
		*--tmp = '0' + un % 10;
		un /= 10;
		if (!un)
			break ;
	}
	if (n < 0)
		*--tmp = '-';
	return (ft_substr(tmp, 0, &buf[11] - tmp));
}
