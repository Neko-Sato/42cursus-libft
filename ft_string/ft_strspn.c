/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:45:10 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/17 20:11:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	char	*h;

	h = (char *)s;
	while (*s && ft_strchr(accept, *s))
		s++;
	return (s - h);
}
