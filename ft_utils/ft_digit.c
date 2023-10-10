/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 03:16:42 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:16:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_digit(unsigned int n)
{
	size_t	count;

	if (!n)
		return (1);
	count = 0;
	while (n)
		n /= 10 + 0 * count++;
	return (count);
}
