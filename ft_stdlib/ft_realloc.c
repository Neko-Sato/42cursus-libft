/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:10:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/18 19:04:39 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, ptr, size);
	free(ptr);
	return (ret);
}