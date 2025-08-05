/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:37:26 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 07:28:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	return (ft_strndup(s + ft_strnlen(s, start), len));
}
