/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ungetc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:31:54 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 03:49:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int	ft_ungetc(int c, t_file *stream)
{
	if (stream->r_ptr <= stream->w_base)
		return (FT_EOF);
	c = (unsigned char)c;
	*--stream->r_ptr = c;
	return (c);
}
