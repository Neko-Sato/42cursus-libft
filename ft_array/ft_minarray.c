/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:43:36 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/05 09:39:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_minarray(int array[], size_t len)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = array[i++];
	while (i < len)
		if (ret > array[i++])
			ret = array[i - 1];
	return (ret);
}
