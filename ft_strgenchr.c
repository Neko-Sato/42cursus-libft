/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:03 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/12 19:02:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strgenchr(t_strgen *strgen, char insert)
{
	if (strgen->error)
		return ;
	strgen->buff[strgen->position++] = insert;
	if (strgen->position > STRGEN_BUFFSIZE)
		ft_strgenclearbuff(strgen);
}
