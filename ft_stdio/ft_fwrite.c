/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:17:54 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 04:25:49 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stddef.h>

size_t	ft_fwrite(const void *ptr, size_t size, size_t nmemb, t_file *stream)
{
	size_t	request;

	request = size * nmemb;
	if (!request)
		return (0);
	return (ft_io_write(ptr, request, stream) / size);
}
