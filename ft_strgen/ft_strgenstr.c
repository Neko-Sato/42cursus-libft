/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgenstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:23 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:09:50 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>

void	ft_strgenstr(t_strgen *strgen, char *insert)
{
	while (!strgen->error && *insert)
		ft_strgenchr(strgen, *insert++);
}
