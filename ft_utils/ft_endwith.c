/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 05:01:03 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/02 05:24:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>

int	ft_endwith(char *str, char *suffix)
{
	size_t	slen;
	size_t	len;

	slen = ft_strlen(str);
	len = ft_strlen(suffix);
	if (slen < len)
		return (0);
	return (!ft_strcmp(str + slen - len, suffix));
}
