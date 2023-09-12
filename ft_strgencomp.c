/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgencomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 18:50:16 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strgencomp(t_strgen *strgen)
{
	char	*ret;

	if (ft_strgenclearbuff(strgen))
		return (NULL);
	ret = strgen->str;
	if (!ret)
	{
		ret = ft_strdup("");
		if (!ret)
			return (NULL);
	}
	strgen->str = NULL;
	strgen->position = 0;
	return (ret);
}
