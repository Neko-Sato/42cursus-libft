/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenfetch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:30:22 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:09:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <ft_string.h>
#include <stdlib.h>

char	*ft_strgenfetch(t_strgen *strgen, size_t len)
{
	char	*ret;
	char	*temp;

	if (strgen->error)
		return (NULL);
	if (!len || !strgen->str)
		return (ft_strdup(""));
	temp = ft_substr(strgen->str, len, -1);
	if (!temp)
		return (NULL);
	ret = ft_substr(strgen->str, 0, len);
	if (!ret)
		free(temp);
	else
	{
		if (!ft_strlen(temp))
		{
			free(temp);
			temp = NULL;
		}
		free(strgen->str);
		strgen->str = temp;
	}
	return (ret);
}
