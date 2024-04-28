/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:37:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/28 15:39:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>

int	ft_ctoi(int c, int radix)
{
	c = ft_tolower(c);
	if (ft_isdigit(c))
		c -= '0';
	else if (ft_isalpha(c))
		c -= 'a' - 10;
	else
		c = -1;
	if (radix <= c)
		c = -1;
	return (c);
}
