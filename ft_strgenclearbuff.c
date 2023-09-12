/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenclearbuff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:43:08 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 18:48:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strgenclearbuff(t_strgen *strgen)
{
	char	*temp;

	if (!strgen->position)
		return (0);
	strgen->buff[strgen->position] = '\0';
	temp = ft_strjoin2(strgen->str, strgen->buff);
	if (!temp)
		return (-1);
	free(strgen->str);
	strgen->str = temp;
	strgen->position = 0;
	return (0);
}
