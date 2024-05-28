/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:45:10 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 02:44:22 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_fclose(t_file *stream)
{
	int	ret;

	ft_fflush(stream);
	if (stream->fileno & _FT_IO_DELETE_DONT_CLOSE)
		ret = 0;
	else
		ret = close(stream->fileno);
	free(stream->r_base);
	free(stream->w_base);
	free(stream);
	return (ret);
}
