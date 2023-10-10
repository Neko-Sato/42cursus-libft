/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:10:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/11 00:06:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (size && (count * size) / size != count)
		return (NULL);
	ret = malloc(count * size);
	if (ret)
		ft_bzero(ret, count * size);
	return (ret);
}