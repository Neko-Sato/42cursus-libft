/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:57:18 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/06 06:21:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string/ft_string.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;

	start = s1;
	end = s1 + ft_strlen(s1);
	while (start < end && ft_strchr(set, *start))
		start++;
	while (start < end && ft_strchr(set, *(end - 1)))
		end--;
	return (ft_substr(start, 0, (end - start)));
}
