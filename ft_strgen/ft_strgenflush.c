/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenflush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:43:08 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/24 13:32:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <ft_string.h>
#include <stdlib.h>

int	ft_strgenflush(t_strgen *strgen)
{
	char	*temp;

	if (!strgen->pos)
		return (0);
	strgen->buf[strgen->pos] = '\0';
	if (strgen->str)
		temp = ft_strjoin(strgen->str, strgen->buf);
	else
		temp = ft_strdup(strgen->buf);
	if (!temp)
		return (-1);
	free(strgen->str);
	strgen->str = temp;
	strgen->pos = 0;
	return (0);
}
