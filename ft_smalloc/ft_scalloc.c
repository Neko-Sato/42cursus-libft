/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:13:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/18 19:27:43 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_smalloc.h>
#include <ft_string.h>
#include <stddef.h>

void	*ft_scalloc(size_t count, size_t size)
{
	void	*ret;

	if (size && (count * size) / size != count)
		return (NULL);
	ret = ft_smalloc(count * size);
	if (ret)
		ft_bzero(ret, count * size);
	return (ret);
}
