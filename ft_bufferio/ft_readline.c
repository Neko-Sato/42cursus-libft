/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 23:59:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_strgen.h>
#include <stdlib.h>

char	*ft_readline(t_bufferio *io)
{
	size_t	len;

	len = 0;
	while (1)
	{
		ft_strgenclearbuff(io->strgen);
		if (io->strgen->str)
		{
			while (!ft_strchr("\n", io->strgen->str[len]))
				len++;
			if (io->strgen->str[len] == '\n')
				return (ft_strgenfetch(io->strgen, ++len));
		}
		if (ft_bufferioread(io))
		{
			if (!io->strgen->str)
				return (NULL);
			return (ft_strgencomp(io->strgen));
		}
	}
}
