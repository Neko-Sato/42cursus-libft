/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:06:28 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/28 14:39:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>
#include <stddef.h>

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (ft_tolower(*s1) != ft_tolower(*s2++))
			return (ft_tolower(*s1) - ft_tolower(*--s2));
		if (!*s1++)
			break ;
	}
	return (0);
}
