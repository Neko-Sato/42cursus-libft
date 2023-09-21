/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufferionew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:14:53 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/21 23:42:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_bufferio	*ft_bufferionew(int fd, int close_on_error)
{
	t_bufferio	*ret;

	if (fd == -1)
		return (NULL);
	ret = (t_bufferio *)malloc(sizeof(t_bufferio));
	if (!ret)
	{
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->strgen = ft_strgennew();
	if (!ret->strgen)
	{
		free(ret);
		if (close_on_error)
			close(fd);
		return (NULL);
	}
	ret->fd = fd;
	return (ret);
}
