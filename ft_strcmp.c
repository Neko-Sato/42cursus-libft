/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:06:28 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/24 14:53:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (!*s1++)
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}
