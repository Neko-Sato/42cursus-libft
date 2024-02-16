/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:03 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/16 12:56:42 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>

void	ft_strgenchr(t_strgen *strgen, char insert)
{
	if (strgen->error)
		return ;
	strgen->buff[strgen->position++] = insert;
	if (strgen->position > strgen->buffsize)
		ft_strgenflush(strgen);
}
