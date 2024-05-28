/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:11:27 by hshimizu          #+#    #+#             */
/*   Updated: 2024/05/29 04:26:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stdio.h>
#include <stddef.h>

size_t	ft_fread(void *ptr, size_t size, size_t nmemb, t_file *stream)
{
	size_t	requested;

	requested = size * nmemb;
	return (ft_io_read(ptr, requested, stream) / size);
}
