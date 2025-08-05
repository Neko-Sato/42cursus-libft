/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:17:33 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/05 19:15:09 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = NULL;
	while (1)
	{
		if (*s == (char)c)
			ret = s;
		if (!*s)
			break ;
		s++;
	}
	return ((char *)ret);
}
