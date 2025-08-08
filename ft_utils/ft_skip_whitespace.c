/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 07:12:12 by hshimizu          #+#    #+#             */
/*   Updated: 2025/08/09 07:17:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype/ft_ctype.h>

char	*ft_skip_whitespace(const char *str)
{
	while (ft_isspace(*str))
		str++;
	return ((char *)str);
}
