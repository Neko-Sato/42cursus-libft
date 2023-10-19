/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgencomp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 19:23:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strgencomp(t_strgen *strgen)
{
	char	*ret;

	ft_strgenflush(strgen);
	if (!strgen->error)
	{
		ret = strgen->str;
		if (!ret)
		{
			ret = ft_strdup("");
			if (!ret)
				strgen->error = 1;
		}
	}
	if (strgen->error)
	{
		free(strgen->str);
		ret = NULL;
	}
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (ret);
}
