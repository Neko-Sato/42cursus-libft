/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgennew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:49:52 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/24 13:29:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <stdlib.h>

t_strgen	*ft_strgennew(size_t size)
{
	t_strgen	*strgen;

	if (!size)
		return (NULL);
	strgen = (t_strgen *)malloc(sizeof(t_strgen) + size);
	if (!strgen)
		return (NULL);
	strgen->str = NULL;
	strgen->pos = 0;
	strgen->size = size;
	return (strgen);
}
