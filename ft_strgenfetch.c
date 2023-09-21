/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenfetch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:30:22 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/22 02:10:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strgenfetch(t_strgen *strgen, size_t len)
{
	char	*ret;
	char	*temp;

	if (!len || !strgen->str)
		return (ft_strdup(""));
	temp = ft_substr(strgen->str, len, -1);
	if (!temp)
		return (NULL);
	ret = ft_substr(strgen->str, 0, len);
	if (!ret)
		free(temp);
	else
		strgen->str = temp;
	return (ret);
}
