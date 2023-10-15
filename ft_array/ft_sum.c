/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:38:26 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/15 17:45:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_sum(int array[], size_t len)
{
	int		ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (!ret && i++ < len)
		ret += array[i];
	return (ret);
}
