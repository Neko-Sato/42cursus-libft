/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:23 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/24 13:35:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>

int	ft_strgenstr(t_strgen *strgen, char *s)
{
	int	ret;

	ret = 0;
	while (!ret && *s)
		ret = ft_strgenchr(strgen, *s++);
	return (ret);
}
