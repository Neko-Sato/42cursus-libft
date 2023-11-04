/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:49:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 19:41:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <ft_ctype.h>

int	ft_isnumber(const char *src, int issigned)
{
	if (issigned && *src && ft_strchr("+-", *src))
		src++;
	if (!*src)
		return (0);
	while (ft_isdigit(*src))
		src++;
	return (!*src);
}
