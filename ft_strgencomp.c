/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgencomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 19:06:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strgencomp(t_strgen *strgen)
{
	char	*ret;

	ft_strgenclearbuff(strgen);
	ret = strgen->str;
	if (!ret)
	{
		ret = ft_strdup("");
		if (!ret)
			strgen->error = 1;
	}
	if (strgen->error)
		ret = NULL;
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (ret);
}
