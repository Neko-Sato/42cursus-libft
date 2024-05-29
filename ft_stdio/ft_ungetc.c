/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ungetc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:31:54 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 16:30:19 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

int	ft_ungetc(int c, t_file *stream)
{
	if (stream->flags & _FT_IO_NO_READS)
		return (FT_EOF);
	if (c == FT_EOF)
		return (FT_EOF);
	if (!stream->r_base || stream->r_ptr <= stream->r_base)
		return (FT_EOF);
	stream->flags &= ~_FT_IO_EOF_SEEN;
	c = (unsigned char)c;
	*--stream->r_ptr = c;
	return (c);
}
