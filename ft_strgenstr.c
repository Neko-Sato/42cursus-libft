/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 18:49:58 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strgenstr(t_strgen *strgen, char *insert)
{
	int	ret;

	ret = 0;
	while (!ret && *insert)
		ret = ft_strgenchr(strgen, *insert++);
	return (ret);
}
