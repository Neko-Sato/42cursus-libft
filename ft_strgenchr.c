/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:03 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 18:49:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strgenchr(t_strgen *strgen, char insert)
{
	strgen->buff[strgen->position++] = insert;
	if (strgen->position > STRGEN_BUFFSIZE)
		return (ft_strgenclearbuff(strgen));
	return (0);
}
