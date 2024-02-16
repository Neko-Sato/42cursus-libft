/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgennew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:49:52 by hshimizu          #+#    #+#             */
/*   Updated: 2024/02/16 12:52:14 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strgen.h>
#include <stdlib.h>

t_strgen	*ft_strgennew(size_t buffsize)
{
	t_strgen	*strgen;

	if (!buffsize)
		return (NULL);
	strgen = (t_strgen *)malloc(sizeof(t_strgen) + buffsize);
	if (!strgen)
		return (NULL);
	strgen->str = NULL;
	strgen->position = 0;
	strgen->error = 0;
	return (strgen);
}
