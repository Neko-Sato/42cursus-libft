/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:31:54 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 02:25:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int	ft_putc(int c, t_file *stream)
{
	unsigned char	ch;

	ch = c;
	if (ft_io_write(&ch, 1, stream) == 1)
		return (ch);
	return (FT_EOF);
}
