/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndarraydel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:30:56 by hshimizu          #+#    #+#             */
/*   Updated: 2023/10/19 21:34:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_ndarraydel(void *array, size_t ndim)
{
	void	*head;
	size_t	i;

	head = array;
	i = 0;
	if (1 < ndim)
		while (((void **)array)[i])
			ft_ndarraydel(((void **)array)[i++], ndim - 1);
	free(head);
}
