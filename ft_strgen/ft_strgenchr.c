/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:03 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/24 13:34:00 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>

int	ft_strgenchr(t_strgen *strgen, int c)
{
	strgen->buf[strgen->pos++] = c;
	if (strgen->pos > strgen->size)
		return (ft_strgenflush(strgen));
	return (0);
}
