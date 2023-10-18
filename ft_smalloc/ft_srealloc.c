/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:10:40 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/18 19:35:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_smalloc.h>
#include <ft_string.h>
#include <stddef.h>

void	*ft_srealloc(void *ptr, size_t size)
{
	void	*ret;

	ret = ft_smalloc(size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, ptr, size);
	ft_sfree(ptr);
	return (ret);
}
