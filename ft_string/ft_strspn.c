/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:26:00 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/07 19:44:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	const char *const	head = s;
	size_t				accept_len;

	accept_len = ft_strlen(accept);
	while (1)
	{
		if (!ft_memchr(accept, *s, accept_len))
			break ;
		if (!*s)
			break ;
		s++;
	}
	return (s - head);
}
