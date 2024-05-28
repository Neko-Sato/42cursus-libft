/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:31:54 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 02:25:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int	ft_getc(t_file *stream)
{
	unsigned char	c;

	if (ft_io_read(&c, 1, stream) == 1)
		return (c);
	return (FT_EOF);
}
