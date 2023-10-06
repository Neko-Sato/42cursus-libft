/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:49:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/07 02:50:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *src)
{
	if (*src && ft_strchr("+-", *src))
		src++;
	if (!*src)
		return (0);
	while (ft_isdigit(*src))
		src++;
	return (!*src);
}
