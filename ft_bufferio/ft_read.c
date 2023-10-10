/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:25:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/10 23:59:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_bufferio.h>
#include <ft_strgen.h>
#include <stdlib.h>

char	*ft_read(t_bufferio *io, int n)
{
	size_t	len;

	len = 0;
	while (1)
	{
		ft_strgenclearbuff(io->strgen);
		if (io->strgen->str)
			len += ft_strlen(&io->strgen->str[len]);
		if (0 <= n && (size_t)n <= len)
			return (ft_strgenfetch(io->strgen, n));
		if (ft_bufferioread(io))
		{
			if (!io->strgen->str)
				return (NULL);
			return (ft_strgencomp(io->strgen));
		}
	}
}
