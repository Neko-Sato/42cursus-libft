/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:26:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:43:51 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char *const	head = s;
	size_t				reject_len;

	reject_len = ft_strlen(reject);
	while (1)
	{
		if (ft_memchr(reject, *s, reject_len))
			break ;
		if (!*s)
			break ;
		s++;
	}
	return (s - head);
}
