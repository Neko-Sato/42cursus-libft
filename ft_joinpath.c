/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:11:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/07 22:27:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define SEPARATE '/'

char	*ft_joinpath(char *base, char *path)
{
	int		separate;
	char	*ret;
	int		size;

	size = ft_strlen(base);
	separate = base[size - 1] == SEPARATE;
	size += ft_strlen(path) + 2 - separate;
	ret = (char *)malloc(size * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, base, size);
	if (!separate)
		ft_strlcat(ret, (char []){SEPARATE}, size);
	ft_strlcat(ret, path, size);
	return (ret);
}
