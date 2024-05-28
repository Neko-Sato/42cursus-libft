/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 01:26:22 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/28 21:58:17 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>

void	ft_clearerr(t_file *stream)
{
	stream->flags &= ~(_FT_IO_EOF_SEEN | _FT_IO_ERR_SEEN);
}
