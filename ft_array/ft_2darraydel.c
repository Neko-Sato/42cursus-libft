/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darraydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:30:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 20:41:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_2darraydel(void *array)
{
	char	**ptr;

	ptr = array;
	while (*ptr)
		free(*ptr++);
	free(array);
}
