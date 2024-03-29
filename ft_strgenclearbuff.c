/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenclearbuff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:43:08 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/04 22:52:21 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strgenclearbuff(t_strgen *strgen)
{
	char	*temp;

	if (!strgen->position || strgen->error)
		return ;
	strgen->buff[strgen->position] = '\0';
	temp = ft_strjoin2(strgen->str, strgen->buff);
	if (!temp)
	{
		strgen->error = 1;
		return ;
	}
	free(strgen->str);
	strgen->str = temp;
	strgen->position = 0;
}
